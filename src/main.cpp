#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <limits>

#define RED "31"
#define YELLOW "33"
#define WHITE "37"

void loading_bar(float total_time);
inline void change_color(std::string color);

class CPU {
	public:
		bool get_cpu_times(uint32_t &idle_time, uint32_t &total_time) const;
		inline int8_t get_cpu_number(void) const;
		inline void set_cpu_number(int8_t cpu_number);

	private:
		int8_t cpu_number;
};

bool CPU::get_cpu_times(uint32_t &idle_time, uint32_t &total_time) const{
	uint32_t time;
	int8_t i = -1;
	std::vector<uint32_t> times;
	/* Jump the lines until reach the good cpu number then read the entire line */
    std::ifstream proc_stat("/proc/stat");

    for(i = -1; i < cpu_number ; i++)
    	proc_stat.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    proc_stat.ignore(5, ' '); //TODO: stocker cette entrée comme nom des cpu au lieu d'un int8_t pout leur numéro

    for (time = 0; proc_stat >> time; times.push_back(time));
    if (times.size() < 4)
        return false;
    idle_time = times[3];
    total_time = std::accumulate(times.begin(), times.end(), 0);

    return true;
}

inline int8_t CPU::get_cpu_number(void) const {
	return this->cpu_number;
}

inline void CPU::set_cpu_number(int8_t cpu_number) {
	/* main cpu is number -1 */
	this->cpu_number = cpu_number;
}

void loading_bar(float total_time) {
	uint8_t i = 0;
	total_time = total_time *0.75;
	uint8_t loading_value = static_cast<uint8_t>(total_time);
	std::string loading = "[                                                                         ]";

	for (i = 1; i< (loading_value - 1); i++)
		loading[i] = '#';
	std::cout << loading << std::endl;
}

inline void change_color(std::string color) {
	std::cout << "\033[" << color << "m";
}

int main(void) {
	std::vector<uint32_t> previous_idle_time;
	std::vector<uint32_t> previous_total_time;
	std::vector<uint32_t> idle_time;
	std::vector<uint32_t> total_time;
    std::vector<CPU> processors;
    int8_t i = 0;
    uint8_t j = 0;
    float idle_time_delta = 0;
    float total_time_delta = 0;
    float utilization = 0;
	CPU new_cpu;

    /*Detect the number of CPU and write it in vector */
    uint8_t numCPU = sysconf(_SC_NPROCESSORS_ONLN);
    for(i = -1; i < numCPU; i++) {
    	new_cpu.set_cpu_number(i);
    	processors.push_back(new_cpu);
    	previous_idle_time.push_back(0);
    	previous_total_time.push_back(0);
    	idle_time.push_back(0);
    	total_time.push_back(0);
    }

    while(true) {
    	system("clear");
    	/* count to numCPU + 1 to count the general cpu and the sub cpu found with the sysconf command */
    	for(j = 0; j < (numCPU + 1); j++) {
    		processors[j].get_cpu_times(idle_time[j], total_time[j]);
            idle_time_delta = idle_time[j] - previous_idle_time[j];
            total_time_delta = total_time[j] - previous_total_time[j];
            utilization = 100.0 * (1.0 - idle_time_delta / total_time_delta);

        	if(utilization > 90.0)
        		change_color(RED);
        	else if(utilization > 70.0)
        		change_color(YELLOW);
        	else
        		change_color(WHITE);

            std::cout << "cpu";
        	if(processors[j].get_cpu_number() != -1)
        		std::cout << " n°" << static_cast<int>(processors[j].get_cpu_number());

            std::cout << ": " << utilization << '%' << std::endl;
            loading_bar( utilization );
            previous_idle_time[j] = idle_time[j];
            previous_total_time[j] = total_time[j];
    	}
        sleep(1);
    }
}



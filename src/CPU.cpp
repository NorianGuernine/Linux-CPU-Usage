/*
 * CPU.cpp
 *
 *  Created on: 18 juin 2022
 *      Author: norian
 */

#include "CPU.hpp"

CPU::CPU() {
	this -> nb_cores = sysconf(_SC_NPROCESSORS_ONLN);
}

uint8_t CPU::getPercentageCpu(std::string str, std::ifstream &cpu_stat) const {
	uint8_t i;
	uint8_t n = 0;
	uint32_t time;
	float idle;
	float total_time = 0;
	float cpu_utilization;
	char number;

	cpu_stat.ignore(5, ' '); // Skip the 'cpu' prefix
	getline(cpu_stat,str);

	for(i = 0; i < 9 ; i++) {
		time = 0;
		number = str.at(n);
	do {
		time = time * 10 + (uint16_t(number) - 48);
		n++;
		number = str.at(n);
	} while(number != ASCII_SP);

	total_time += time;
	n++;

	if(i==3)
		idle = time;
	}

	cpu_utilization = (1-(idle/total_time)) *100;

	return static_cast<uint8_t>(cpu_utilization);
}

uint8_t CPU::getCPUUsage() const {

	std::ifstream cpu_stat;
	std::string str;
	uint8_t cpu_utilization;

	cpu_stat.open("/proc/stat");

	if(cpu_stat.is_open()) {
		getline(cpu_stat,str);
		cpu_utilization = this->getPercentageCpu(str, cpu_stat);
		cpu_stat.close();
	} else {
		std::cerr << "Unable to open /proc/stat \n";
		return -1;
	}
	return cpu_utilization;
}

uint8_t Core::getCPUUsage(uint8_t CPUNumber) const {
	/*
	 * CPUNumber is the core number, it starts at 0
	 */

	uint8_t i;
	uint8_t cpu_utilization;
	std::ifstream cpu_stat;
	std::string str;

	cpu_stat.open("/proc/stat");

	if(cpu_stat.is_open()) {
		/* skip all cpu infos until we get the good cpu */
		for(i = 0; i< (CPUNumber+1); i++) {
			getline(cpu_stat,str);
		}

		cpu_utilization = this->getPercentageCpu(str, cpu_stat);
		cpu_stat.close();
	} else {
		std::cerr << "Unable to open /proc/stat \n";
		return -1;
	}

	return cpu_utilization;
}


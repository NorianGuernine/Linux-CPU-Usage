#include "CPU.hpp"


int main() {

	Core info_proc;
	CPU info_cpu;
	uint8_t core_utilization;
	uint8_t cpu_utilization;

	core_utilization = info_proc.getCPUUsage(1);
	cpu_utilization = info_cpu.getCPUUsage();

	std::cout << "Utilization cpu = " << static_cast<int>(cpu_utilization) << "\n";
	std::cout << "Utilization core 0 = " << static_cast<int>(core_utilization) << "\n";
}

#include "CPU.hpp"

using namespace std;

int main() {

	Core info_proc;
	uint8_t core_utilization;

	core_utilization = info_proc.getCoreUsage(0);

	cout << "Utilization core 0 = " << core_utilization << "\n";
}

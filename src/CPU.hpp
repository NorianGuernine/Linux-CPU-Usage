/*
 * CPU.hpp
 *
 *  Created on: 19 juin 2022
 *      Author: norian
 */

#ifndef CPU_HPP_
#define CPU_HPP_

#include <iostream>
#include <unistd.h>
#include <fstream>
#include <string>

class CPU {
	public:
		CPU();
		uint8_t getPercentageCpu(std::string str, std::ifstream &cpu_file) const;

	protected:
		uint8_t nb_cores;
};

class Core : public CPU {
	public:
		uint8_t getCoreUsage (uint8_t CPUNumber) const;
};

#endif /* CPU_HPP_ */

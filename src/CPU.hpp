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

class CPU {
	public:
		CPU();
		uint8_t getNbCores() const;

	private:
		uint8_t nb_cores;
};

class core : public CPU {
	uint8_t getCoreUsage () const;
};

#endif /* CPU_HPP_ */

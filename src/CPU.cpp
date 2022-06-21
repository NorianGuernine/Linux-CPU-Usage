/*
 * CPU.cpp
 *
 *  Created on: 18 juin 2022
 *      Author: norian
 */

#include "CPU.hpp"


using namespace std;

CPU::CPU() {
	this -> nb_cores = sysconf(_SC_NPROCESSORS_ONLN);
}

inline uint8_t CPU::getNbCores() const {
	return this -> nb_cores;
}



/*
 * gqandroidrecordsl.cpp
 *
 *  Created on: 2011-9-8
 *      Author: root
 */

#include "../include/gqandroidrecordsl.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>

GqAndroidRecordSL::GqAndroidRecordSL() {

}

GqAndroidRecordSL::~GqAndroidRecordSL() {
}

void GqAndroidRecordSL::received_buf_from_recorder(short *record_buf,
		unsigned long buf_size_in_byte) {
	std::cout << "received_buf_from_recorder begin" << std::endl;
	for (unsigned long i = 0; i < buf_size_in_byte/sizeof(short); ++i) {
		std::cout << std::right << std::setw(sizeof(short) * 2) << std::hex
				<< record_buf[i] << std::setfill('0');
		if ((i+1) % 10 == 0) {
			std::cout << std::endl;
		} else if ((i+1) % 10 > 0) {
			std::cout << ",";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "received_buf_from_recorder end" << std::endl;
}

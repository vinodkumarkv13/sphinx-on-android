#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#include <assert.h>
#include <iomanip>
#include <unistd.h>

#include <pocketsphinx.h>

#include <gqandroidsphinx.h>
#include <gqandroidrecordsl.h>
#include <igqsphinx.h>
#include <gqrecordalsa.h>
//local

int main(void) {
	IGqSphinx *psphinx = new GqAndroidSphinx;
	IGqRecord *precord = new GqRecordALSA;
	std::cout << "main 1" << std::endl;
	psphinx->init_sphinx(precord);
	std::cout << "main 1.2" << std::endl;
	psphinx->start_recognize_from_mic();

	while (true) {
		::usleep(1000000 * 5);
	}

	std::cout << "main 2" << std::endl;
	psphinx->end_recognize_from_mic();

	std::string srecog = psphinx->get_recognized_str();
	std::cout << srecog << std::endl;

	if (precord) {
		delete precord;
	}

	if (psphinx)
		delete psphinx;

	return 0;
}

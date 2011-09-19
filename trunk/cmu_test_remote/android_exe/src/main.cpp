#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>

#include <assert.h>
#include <iomanip>
#include <unistd.h>


#include <pocketsphinx.h>

#include <gqrecordsl.h>
#include <gqandroidsphinx.h>
#include <gqandroidrecordsl.h>
#include <igqsphinx.h>


int main(void) {
	IGqSphinx *psphinx = new GqAndroidSphinx;
	std::cout << "main 1" << std::endl;

	IGqRecord *precord = new GqRecordSL;
	psphinx->init_sphinx(precord);
	std::cout << "main 1.2" << std::endl;
	psphinx->start_recognize_from_mic();

	::usleep(1000000*5);
	
	

	std::cout << "main 2" << std::endl;
	psphinx->end_recognize_from_mic();

	std::string srecog = psphinx->get_recognized_str();
	std::cout << srecog << std::endl;

	if (psphinx)
		delete psphinx;

	return 0;
}


/*
 * gqandroidsphinx.cpp
 *
 *  Created on: 2011-9-13
 *      Author: root
 */

#include <gqandroidsphinx.h>

#include <iostream>
#include <iomanip>
#include <unistd.h>

#include <stdlib.h>
#include <pocketsphinx.h>

//#include <gqrecordsl.h>

GqAndroidSphinx::GqAndroidSphinx() :
		m_shmm("/home/q/Workspace/data/model/hmm/"), m_slm(
				"/home/q/Workspace/data/model/lm/zh_broadcastnews_64000_utf8.DMP"), m_sdict(
				"/home/q/Workspace/data/model/lm/zh_broadcastnews_utf8.dic") {

}

GqAndroidSphinx::~GqAndroidSphinx() {
	destroy_sphinx();
}

bool GqAndroidSphinx::init_sphinx(IGqRecord *precoder) {
	m_pconfig = cmd_ln_init(NULL, ps_args(), TRUE, "-hmm", m_shmm.c_str(),
			"-lm", m_slm.c_str(), "-dict", m_sdict.c_str(), NULL);
	if (m_pconfig == NULL) {
		return false;
	}

	if (m_pdecoder) {
		ps_free(m_pdecoder);
		m_pdecoder = NULL;
	}

	m_pdecoder = ps_init(m_pconfig);
	if (m_pdecoder == 0) {
		return false;
	}

	if (m_precord) {
		m_precord->stop_record();
		delete m_precord;
		m_precord = NULL;
	}

	m_precord = precoder;
	m_precord->set_record_cb(this);
	m_precord->init_recorder();

	return true;
}

/*
 * author root
 *
 * To change this generated comment edit the template variable "comment":
 * Window > Preferences > C/C++ > Editor > Templates.
 */

bool GqAndroidSphinx::start_recognize_from_mic() {
	int rv = ps_start_utt(m_pdecoder, "ps_start_utt");
	if (rv < 0)
		return false;

	return m_precord->start_record();;
}

bool GqAndroidSphinx::end_recognize_from_mic() {
	m_precord->stop_record();
	int rv = ps_end_utt(m_pdecoder);
	if (rv < 0)
		return false;
	return true;
}

std::string GqAndroidSphinx::get_recognized_str() {
	int32 score = 0;
	char const *uttid = NULL;
	return ps_get_hyp(m_pdecoder, &score, &uttid);
}

void GqAndroidSphinx::received_buf_from_recorder(short *record_buf,
		unsigned long buf_size_in_byte) {
	std::cout << "received_buf_from_recorder begin" << std::endl;
	for (unsigned long i = 0; i < buf_size_in_byte / sizeof(short); ++i) {
		std::cout << std::right << std::setw(sizeof(short) * 2) << std::hex
				<< record_buf[i] << std::setfill('0');
		if ((i + 1) % 10 == 0) {
			std::cout << std::endl;
		} else if ((i + 1) % 10 > 0) {
			std::cout << ",";
		}
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "received_buf_from_recorder end" << std::endl;

	ps_process_raw(m_pdecoder, record_buf, buf_size_in_byte, FALSE, FALSE);
}

void GqAndroidSphinx::destroy_sphinx() {

}


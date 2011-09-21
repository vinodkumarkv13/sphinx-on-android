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
		m_shmm("/home/q/Workspace/sphinx-on-android/trunk/data/model/hmm"), m_slm(
				"/home/q/Workspace/sphinx-on-android/trunk/data/model/lm/zh_broadcastnews_64000_utf8.DMP"), m_sdict(
				"/home/q/Workspace/sphinx-on-android/trunk/data/model/lm/zh_broadcastnews_utf8.dic") {
	pthread_mutex_init(&m_pt_mutex,NULL);
	m_fout.open("sphinx_record.raw",std::ios::out|std::ios::binary|std::ios::trunc);
}

GqAndroidSphinx::~GqAndroidSphinx() {
	destroy_sphinx();
	m_fout.close();
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
	int rv = ps_start_utt(m_pdecoder, NULL);
	if (rv < 0)
		return false;

	return m_precord->start_record();
}

bool GqAndroidSphinx::end_recognize_from_mic() {
	m_precord->stop_record();
	pthread_mutex_lock(&m_pt_mutex);
	int rv = ps_end_utt(m_pdecoder);
	pthread_mutex_unlock(&m_pt_mutex);
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
	m_fout.write((char *)record_buf,buf_size_in_byte);
	pthread_mutex_lock(&m_pt_mutex);
	ps_process_raw(m_pdecoder, record_buf, buf_size_in_byte/2, FALSE, FALSE);
	pthread_mutex_unlock(&m_pt_mutex);
}

void GqAndroidSphinx::destroy_sphinx() {

}


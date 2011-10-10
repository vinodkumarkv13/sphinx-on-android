/*
 * gqandroidsphinx.cpp
 *
 *  Created on: 2011-9-13
 *      Author: root
 */

#include <gqandroidsphinx.h>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <unistd.h>

#include <stdlib.h>
#include <pocketsphinx.h>

#include <gqrecordsl.h>

#include <gqcomm.h>

GqAndroidSphinx::GqAndroidSphinx() :
		m_shmm("/sdcard/cmusphinx/zh_CN/model/02/hmm"), m_slm(
				"/sdcard/cmusphinx/zh_CN/model/02/lm/an4.lm.DMP"), m_sdict(
				"/sdcard/cmusphinx/zh_CN/model/02/lm/an4.dic"), m_precord(NULL) {
	pthread_mutex_init(&m_pt_mutex, NULL);

	char szCurDir[256];
	::getcwd(szCurDir,256);
	LOGD("%s",szCurDir);
	m_fout.open("/sdcard/cmusphinx/zh_CN/model/02/sphinx_record.raw",
			std::ios::out | std::ios::binary | std::ios::trunc);
}

GqAndroidSphinx::~GqAndroidSphinx() {
	destroy_sphinx();
	m_fout.close();
}

bool GqAndroidSphinx::init_sphinx(IGqRecord *precord) {
	m_pconfig = cmd_ln_init(NULL, ps_args(), TRUE, "-hmm", m_shmm.c_str(),
			"-lm", m_slm.c_str(), "-dict", m_sdict.c_str(), NULL);
	if (m_pconfig == NULL) {
		return false;
	}

	if (m_pdecoder) {
		LOGD("m_pdecoder");
		ps_free(m_pdecoder);
		m_pdecoder = NULL;
	}
	m_pdecoder = ps_init(m_pconfig);
	if (m_pdecoder == 0) {
		return false;
	}
	if (m_precord) {
		LOGD("delete m_precord;");
		m_precord->stop_record();
		delete m_precord;
		m_precord = NULL;
	}
	m_precord = precord;
	m_precord->set_record_cb(this);
	m_precord->init_recorder();
	LOGD("after init_recorder");
	return true;
}

/*
 * author root
 *
 * To change this generated comment edit the template variable "comment":
 * Window > Preferences > C/C++ > Editor > Templates.
 */

bool GqAndroidSphinx::start_recognize_from_mic() {

	LOGD("before start_recognize_from_mic");
	int rv = ps_start_utt(m_pdecoder, "ps_start_utt");
	if (rv < 0)
		return false;LOGD("after start_recognize_from_mic");
	return m_precord->start_record();
}

bool GqAndroidSphinx::end_recognize_from_mic() {
	m_precord->stop_record();
	pthread_mutex_lock(&m_pt_mutex);
	int rv = ps_end_utt(m_pdecoder);
	pthread_mutex_unlock(&m_pt_mutex);
	m_fout.close();
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
	m_fout.write((char *) record_buf, buf_size_in_byte);

	pthread_mutex_lock(&m_pt_mutex);
	LOGD("received_buf_from_recorder before");
	ps_process_raw(m_pdecoder, record_buf, buf_size_in_byte / sizeof(int16),
			TRUE, FALSE);
	LOGD("received_buf_from_recorder end");
	pthread_mutex_unlock(&m_pt_mutex);

}

void GqAndroidSphinx::destroy_sphinx() {

}


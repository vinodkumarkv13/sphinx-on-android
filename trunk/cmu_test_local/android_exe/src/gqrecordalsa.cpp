/*
 * gqrecordalsa.cpp
 *
 *  Created on: 2011-9-14
 *      Author: root
 */

#include "../include/gqrecordalsa.h"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

GqRecordALSA::GqRecordALSA() :
		m_pcapture_handle(NULL), m_hw_params(NULL), m_bpause(false) {

}

GqRecordALSA::~GqRecordALSA() {

}

bool GqRecordALSA::init_recorder() {
	return true;
}

void *fn_record(void *precord) {
	GqRecordALSA *precord_alsa = (GqRecordALSA *) precord;
	assert(precord_alsa != NULL);

	while (true) {
		snd_pcm_status_t record_status;
		snd_pcm_status(precord_alsa->m_pcapture_handle, &record_status);
		_snd_pcm_state state = snd_pcm_status_get_state(&record_status);
		switch (state) {
		case SND_PCM_STATE_PAUSED:
			continue;
		case SND_PCM_STATE_DISCONNECTED:
			return NULL;
		}

		int err;
		short buf[512] = { 0 };
		if ((err = snd_pcm_readi(precord_alsa->m_pcapture_handle, buf, 512))
				< 0) {
			fprintf(stderr, "read from audio interface failed (%s)\n",
					snd_strerror(err));
			return NULL;
		}
		precord_alsa->get_record_cb()->received_buf_from_recorder(buf,512*sizeof(short));
	}
	return NULL;
}

bool GqRecordALSA::start_record() {
	create_record();

	snd_pcm_hw_params_free (hw_params);

	int err = -1;
	if ((err = snd_pcm_prepare(m_pcapture_handle)) < 0) {
		fprintf(stderr, "cannot prepare audio interface for use (%s)\n",
				snd_strerror(err));
		exit(1);
	}

	pthread_t ntid;
	pthread_create(&ntid, NULL, fn_record, this);
	return true;
}

bool GqRecordALSA::pause_record() {
	snd_pcm_pause(m_pcapture_handle, m_bpause);
	m_bpause = !m_bpause;
	return true;
}

bool GqRecordALSA::stop_record() {
	snd_pcm_close(m_pcapture_handle);
	return true;
}

bool GqRecordALSA::create_record() {
	int err;
	if ((err = snd_pcm_open(&m_pcapture_handle, "default",
			SND_PCM_STREAM_CAPTURE, 0)) < 0) {
		fprintf(stderr, "cannot open audio device (%s)\n", snd_strerror(err));
		exit(1);
	}

	if ((err = snd_pcm_hw_params_malloc(&m_hw_params)) < 0) {
		fprintf(stderr, "cannot allocate hardware parameter structure (%s)\n",
				snd_strerror(err));
		exit(1);
	}

	if ((err = snd_pcm_hw_params_any(m_pcapture_handle, m_hw_params)) < 0) {
		fprintf(stderr, "cannot initialize hardware parameter structure (%s)\n",
				snd_strerror(err));
		exit(1);
	}

	if ((err = snd_pcm_hw_params_set_access(m_pcapture_handle, m_hw_params,
			SND_PCM_ACCESS_RW_INTERLEAVED)) < 0) {
		fprintf(stderr, "cannot set access type (%s)\n", snd_strerror(err));
		exit(1);
	}

	if ((err = snd_pcm_hw_params_set_format(m_pcapture_handle, m_hw_params,
			SND_PCM_FORMAT_S16_LE)) < 0) {
		fprintf(stderr, "cannot set sample format (%s)\n", snd_strerror(err));
		exit(1);
	}

	unsigned int nsp = 16000;
	int nrt = 0;
	if ((err = snd_pcm_hw_params_set_rate_near(m_pcapture_handle, m_hw_params,
			&nsp, &nrt)) < 0) {
		fprintf(stderr, "cannot set sample rate (%s)\n", snd_strerror(err));
		exit(1);
	}

	if ((err = snd_pcm_hw_params_set_channels(m_pcapture_handle, m_hw_params, 1))
			< 0) {
		fprintf(stderr, "cannot set channel count (%s)\n", snd_strerror(err));
		exit(1);
	}

	if ((err = snd_pcm_hw_params(m_pcapture_handle, m_hw_params)) < 0) {
		fprintf(stderr, "cannot set parameters (%s)\n", snd_strerror(err));
		exit(1);
	}
	return true;
}

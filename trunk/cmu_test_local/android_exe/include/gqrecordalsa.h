/*
 * gqrecordalsa.h
 *
 *  Created on: 2011-9-14
 *      Author: root
 */

#ifndef GQRECORDALSA_H_
#define GQRECORDALSA_H_

#include <igqrecord.h>
#include <alsa/asoundlib.h>

class GqRecordALSA: public IGqRecord {
public:
	GqRecordALSA();
	virtual ~GqRecordALSA();

private:
	bool init_recorder();
	bool start_record();
	bool pause_record();
	bool stop_record();

	bool create_record();

	friend void *fn_record(void *precord);

private:
	snd_pcm_t *m_pcapture_handle;
	snd_pcm_hw_params_t *m_hw_params;
	bool m_bpause;
};

#endif /* GQRECORDALSA_H_ */

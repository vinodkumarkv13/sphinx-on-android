/*
 * GQRECORDSL.h
 *
 *  Created on: 2011-9-7
 *      Author: root
 */

#ifndef GQRECORDSL_H_
#define GQRECORDSL_H_

#include "igqrecord.h"

#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>

#define RECORDER_FRAMES (512)


class GqRecordSL: public IGqRecord {
public:
	GqRecordSL();
	virtual ~GqRecordSL();

private:
	bool init_recorder();
	bool start_record();
	bool pause_record();
	bool stop_record();

private:
	bool create_sl_engine();
	bool create_sl_recorder();

	friend void sl_record_callback(SLAndroidSimpleBufferQueueItf bq, void *context);

private:
	short        *m_p_sound_buf;
	// engine interfaces
	SLObjectItf m_sl_engine_object;
	SLEngineItf m_sl_engine_engine;

	// recorder interfaces
	SLObjectItf m_sl_recorder_object;
	SLRecordItf m_sl_recorder_record;
	SLAndroidSimpleBufferQueueItf m_sl_recorder_buf_queue;
};

#endif /* GQRECORDSL_H_ */

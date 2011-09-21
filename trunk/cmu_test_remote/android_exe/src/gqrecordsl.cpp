/*
 * gqrecordsl.cpp
 *
 *  Created on: 2011-9-7
 *      Author: root
 */

#include "gqrecordsl.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

#include <assert.h>
#include <unistd.h>

#include <gqcomm.h>

static short recorderBuffer[RECORDER_FRAMES];

void sl_record_callback(SLAndroidSimpleBufferQueueItf bq, void *context) {
	assert(NULL != context);
	GqRecordSL* lprecord = (GqRecordSL*) context;
	assert(bq == lprecord->m_sl_recorder_buf_queue);

	LOGD("enter sl_record_callback");

	SLresult result = (*bq)->Enqueue(bq, recorderBuffer,
			RECORDER_FRAMES * sizeof(short) );

	assert(SL_RESULT_SUCCESS == result);

	LOGD("before get_record_cb");

	IGqRecordCB *precord_cb = lprecord->get_record_cb();
	assert(NULL != precord_cb && "the IGqRecordCB not set!");

	LOGD("exit get_record_cb");

	precord_cb->received_buf_from_recorder(recorderBuffer,
			RECORDER_FRAMES * sizeof(short));
	LOGD("exit sl_record_callback");
}

GqRecordSL::GqRecordSL() :
		m_p_sound_buf(NULL), m_sl_engine_object(NULL), m_sl_engine_engine(NULL), m_sl_recorder_object(
				NULL), m_sl_recorder_record(NULL), m_sl_recorder_buf_queue(NULL) {

}

GqRecordSL::~GqRecordSL() {

}

bool GqRecordSL::start_record() {
	SLresult result;
	LOGD("startRecording inner start");
	// in case already recording, stop recording and clear buffer queue
	result = (*m_sl_recorder_record)->SetRecordState(m_sl_recorder_record,
			SL_RECORDSTATE_STOPPED);
	assert(SL_RESULT_SUCCESS == result);
	result = (*m_sl_recorder_buf_queue)->Clear(m_sl_recorder_buf_queue);
	assert(SL_RESULT_SUCCESS == result);

	unsigned long buf_len = RECORDER_FRAMES;
	//m_p_sound_buf = new short(buf_len);
	// enqueue an empty buffer to be filled by the recorder
	// (for streaming recording, we would enqueue at least 2 empty buffers to start things off)
	result = (*m_sl_recorder_buf_queue)->Enqueue(m_sl_recorder_buf_queue,
			recorderBuffer, buf_len * sizeof(short));

	// the most likely other result is SL_RESULT_BUFFER_INSUFFICIENT,
	// which for this code example would indicate a programming error
	assert(SL_RESULT_SUCCESS == result);
	// start recording
	result = (*m_sl_recorder_record)->SetRecordState(m_sl_recorder_record,
			SL_RECORDSTATE_RECORDING);
	assert(SL_RESULT_SUCCESS == result);
	LOGD("startRecording inner end");
	return true;
}

bool GqRecordSL::stop_record() {
	SLresult result = (*m_sl_recorder_record)->SetRecordState(
			m_sl_recorder_record, SL_RECORDSTATE_STOPPED);

	std::cout << "stop_record" << std::endl << std::endl << std::endl << std::endl;

	assert(SL_RESULT_SUCCESS == result);
	return false;
}

bool GqRecordSL::pause_record() {
	SLresult result = (*m_sl_recorder_record)->SetRecordState(
			m_sl_recorder_record, SL_RECORDSTATE_PAUSED);
	assert(SL_RESULT_SUCCESS == result);
	return false;
}

bool GqRecordSL::init_recorder() {
	if (!create_sl_engine()) {
		return false;
	}

	if (create_sl_recorder())
		return false;

	return true;
}

bool GqRecordSL::create_sl_engine() {
	SLresult result;

	// create engine
	result = slCreateEngine(&m_sl_engine_object, 0, NULL, 0, NULL, NULL);
	assert(SL_RESULT_SUCCESS == result);

	// realize the engine
	result = (*m_sl_engine_object)->Realize(m_sl_engine_object,
			SL_BOOLEAN_FALSE);
	assert(SL_RESULT_SUCCESS == result);

	// get the engine interface, which is needed in order to create other objects
	result = (*m_sl_engine_object)->GetInterface(m_sl_engine_object,
			SL_IID_ENGINE, &m_sl_engine_engine);
	assert(SL_RESULT_SUCCESS == result);

	return true;
}

bool GqRecordSL::create_sl_recorder() {
	SLresult result;

	// configure audio source
	LOGD("configure audio source");
	SLDataLocator_IODevice loc_dev = { SL_DATALOCATOR_IODEVICE,
			SL_IODEVICE_AUDIOINPUT, SL_DEFAULTDEVICEID_AUDIOINPUT, NULL };
	SLDataSource audioSrc = { &loc_dev, NULL };

	// configure audio sink
	LOGD("configure audio sink");
	SLDataLocator_AndroidSimpleBufferQueue loc_bq = {
			SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE, 2 };
	SLDataFormat_PCM format_pcm = { SL_DATAFORMAT_PCM, 1, SL_SAMPLINGRATE_16,
			SL_PCMSAMPLEFORMAT_FIXED_16, SL_PCMSAMPLEFORMAT_FIXED_16,
			SL_SPEAKER_FRONT_CENTER, SL_BYTEORDER_LITTLEENDIAN };
	SLDataSink audioSnk = { &loc_bq, &format_pcm };

	// create audio recorder
	LOGD("create audio recorder");
	// (requires the RECORD_AUDIO permission)
	const SLInterfaceID id[1] = { SL_IID_ANDROIDSIMPLEBUFFERQUEUE };
	const SLboolean req[1] = { SL_BOOLEAN_TRUE };
	result = (*m_sl_engine_engine)->CreateAudioRecorder(m_sl_engine_engine,
			&m_sl_recorder_object, &audioSrc, &audioSnk, 1, id, req);
	if (SL_RESULT_SUCCESS != result) {
		LOGD("create audio recorder failed");
		return false;
	}

	// realize the audio recorder
	LOGD("realize the audio recorder");
	result = (*m_sl_recorder_object)->Realize(m_sl_recorder_object,
			SL_BOOLEAN_FALSE);
	if (SL_RESULT_SUCCESS != result) {
		LOGD("realize the audio recorder failed");
		return false;
	}

	// get the record interface

	LOGD("get the record interface");
	result = (*m_sl_recorder_object)->GetInterface(m_sl_recorder_object,
			SL_IID_RECORD, &m_sl_recorder_record);
	assert(SL_RESULT_SUCCESS == result);

	// get the buffer queue interface
	result = (*m_sl_recorder_object)->GetInterface(m_sl_recorder_object,
			SL_IID_ANDROIDSIMPLEBUFFERQUEUE, &m_sl_recorder_buf_queue);
	assert(SL_RESULT_SUCCESS == result);

	// register callback on the buffer queue

	result = (*m_sl_recorder_buf_queue)->RegisterCallback(
			m_sl_recorder_buf_queue, sl_record_callback, this);
	assert(SL_RESULT_SUCCESS == result);

	LOGD("create_sl_recorder suc");
	return true;

}

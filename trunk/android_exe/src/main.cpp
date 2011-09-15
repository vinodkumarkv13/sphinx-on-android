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

//
//void test_opensl();
//
//// engine interfaces
//static SLObjectItf engineObject = NULL;
//static SLEngineItf engineEngine;
//
//// recorder interfaces
//static SLObjectItf recorderObject = NULL;
//static SLRecordItf recorderRecord;
//static SLAndroidSimpleBufferQueueItf recorderBufferQueue;
//
//// 5 seconds of recorded audio at 16 kHz mono, 16-bit signed little endian
//#define RECORDER_FRAMES (16000 * 5)
//static short recorderBuffer[RECORDER_FRAMES];
//static unsigned recorderSize = 0;
//

/*
// this callback handler is called every time a buffer finishes recording
void bqRecorderCallback(SLAndroidSimpleBufferQueueItf bq, void *context)
{
	int *ptest = (int *)context;
	std::cout << "enter bqRecorderCallback : " << *ptest << std::endl;
    assert(bq == recorderBufferQueue);
    //assert(NULL == context);

    (*bq)->Enqueue(bq,recorderBuffer,RECORDER_FRAMES*sizeof(short));
    for (int i = 0; i < RECORDER_FRAMES; ++i) {
    	std::cout  << std::right << std::setw(sizeof(short)*2) << std::hex << recorderBuffer[i] << std::setfill('0') ;
    	if (i % 10 == 0) {
    		std::cout << std::endl;
		} else if(i % 10 > 0) {
			std::cout << ",";
		}
	}
}
*/




// create the engine and output mix objects
//bool createEngine()
//{
//    SLresult result;
//
//    // create engine
//    result = slCreateEngine(&engineObject, 0, NULL, 0, NULL, NULL);
//    assert(SL_RESULT_SUCCESS == result);
//
//    // realize the engine
//    result = (*engineObject)->Realize(engineObject, SL_BOOLEAN_FALSE);
//    assert(SL_RESULT_SUCCESS == result);
//
//    // get the engine interface, which is needed in order to create other objects
//    result = (*engineObject)->GetInterface(engineObject, SL_IID_ENGINE, &engineEngine);
//    assert(SL_RESULT_SUCCESS == result);
//
//    return true;
//}
//
//
//int test = 5556545;
//
//// create audio recorder
//bool createAudioRecorder()
//{
//    SLresult result;
//
//    // configure audio source
//    std::cout << "configure audio source" << std::endl;
//    SLDataLocator_IODevice loc_dev = {SL_DATALOCATOR_IODEVICE, SL_IODEVICE_AUDIOINPUT,
//            SL_DEFAULTDEVICEID_AUDIOINPUT, NULL};
//    SLDataSource audioSrc = {&loc_dev, NULL};
//
//    // configure audio sink
//    std::cout << "configure audio sink" << std::endl;
//    SLDataLocator_AndroidSimpleBufferQueue loc_bq = {SL_DATALOCATOR_ANDROIDSIMPLEBUFFERQUEUE, 2};
//    SLDataFormat_PCM format_pcm = {SL_DATAFORMAT_PCM, 1, SL_SAMPLINGRATE_16,
//        SL_PCMSAMPLEFORMAT_FIXED_16, SL_PCMSAMPLEFORMAT_FIXED_16,
//        SL_SPEAKER_FRONT_CENTER, SL_BYTEORDER_LITTLEENDIAN};
//    SLDataSink audioSnk = {&loc_bq, &format_pcm};
//
//    // create audio recorder
//    std::cout << "create audio recorder" << std::endl;
//    // (requires the RECORD_AUDIO permission)
//    const SLInterfaceID id[1] = {SL_IID_ANDROIDSIMPLEBUFFERQUEUE};
//    const SLboolean req[1] = {SL_BOOLEAN_TRUE};
//    result = (*engineEngine)->CreateAudioRecorder(engineEngine, &recorderObject, &audioSrc,
//            &audioSnk, 1, id, req);
//    if (SL_RESULT_SUCCESS != result) {
//    	std::cout << "create audio recorder failed" << std::endl;
//        return false;
//    }
//
//    // realize the audio recorder
//    std::cout << "realize the audio recorder" << std::endl;
//    result = (*recorderObject)->Realize(recorderObject, SL_BOOLEAN_FALSE);
//    if (SL_RESULT_SUCCESS != result) {
//    	std::cout << "realize the audio recorder failed" << std::endl;
//        return false;
//    }
//
//    // get the record interface
//
//    std::cout << "get the record interface" << std::endl;
//    result = (*recorderObject)->GetInterface(recorderObject, SL_IID_RECORD, &recorderRecord);
//    assert(SL_RESULT_SUCCESS == result);
//
//    // get the buffer queue interface
//    result = (*recorderObject)->GetInterface(recorderObject, SL_IID_ANDROIDSIMPLEBUFFERQUEUE,
//            &recorderBufferQueue);
//    assert(SL_RESULT_SUCCESS == result);
//
//    // register callback on the buffer queue
//
//    result = (*recorderBufferQueue)->RegisterCallback(recorderBufferQueue, bqRecorderCallback,
//            &test);
//    assert(SL_RESULT_SUCCESS == result);
//
//    return true;
//}
//
//// set the recording state for the audio recorder
//void startRecording()
//{
//    SLresult result;
//
//    // in case already recording, stop recording and clear buffer queue
//    result = (*recorderRecord)->SetRecordState(recorderRecord, SL_RECORDSTATE_STOPPED);
//    assert(SL_RESULT_SUCCESS == result);
//    result = (*recorderBufferQueue)->Clear(recorderBufferQueue);
//    assert(SL_RESULT_SUCCESS == result);
//
//    // the buffer is not valid for playback yet
//    recorderSize = 0;
//
//    // enqueue an empty buffer to be filled by the recorder
//    // (for streaming recording, we would enqueue at least 2 empty buffers to start things off)
//    result = (*recorderBufferQueue)->Enqueue(recorderBufferQueue, recorderBuffer,
//            RECORDER_FRAMES * sizeof(short));
//    // the most likely other result is SL_RESULT_BUFFER_INSUFFICIENT,
//    // which for this code example would indicate a programming error
//    assert(SL_RESULT_SUCCESS == result);
//
//    std::cout << "SetRecordState: SL_RECORDSTATE_RECORDING" << std::endl;
//    // start recording
//    result = (*recorderRecord)->SetRecordState(recorderRecord, SL_RECORDSTATE_RECORDING);
//    assert(SL_RESULT_SUCCESS == result);
//    std::cout << "startRecording inner end" << std::endl;
//}
//
//void test_opensl(){
//	std::cout << "enter test_opensl" << std::endl;
//	bool bsuc = createEngine();
//	if (!bsuc)
//		return ;
//
//	std::cout << "createEngine suc" << std::endl;
//
//	bsuc = createAudioRecorder();
//	if (!bsuc)
//		return ;
//	std::cout << "createAudioRecorder suc" << std::endl;
//
//	std::cout << "startRecording" << std::endl;
//	startRecording();
//	std::cout << "startRecording end" << std::endl;
//}

void test_sphinx(){
	 /*cmd_ln_t *config = cmd_ln_init(NULL,ps_args(),TRUE,
	    		"-hmm", "/data/td/model/hmm/",
	    		"-lm",  "/data/td/model/lm/zh_broadcastnews_64000_utf8.DMP",
	    		"-dict","/data/td/model/lm/zh_broadcastnews_utf8.dic",
	    		NULL);
	    if (config == NULL) {
			return 1;
		}

	    ps_decoder_t *ps = ps_init(config);
	    if (ps == 0) {
			return 1;
		}

	    FILE *fh;
	    fh = fopen("/data/td/sound/aaa.wav","rb");
	    if (fh == 0) {
	    	perror("failed to open goforward.raw");
			return 1;
		}

	    printf("ps_decode_raw 1: \n\n\n\n\n");

	    int rv = ps_decode_raw(ps,fh,"goforward_t",-1);
	    if (rv < 0) {
			return 1;
		}

	    char const *hyp,*uutid;
	    int32 score;
	    hyp = ps_get_hyp(ps,&score,&uutid);
	    if (hyp == NULL) {
			return 1;
		}

	    printf("recognized: %s\n",hyp);*/
}

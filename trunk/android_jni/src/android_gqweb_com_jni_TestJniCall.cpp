/*
 * android_gqweb_com_jni_TestJniCall.cpp
 *
 *  Created on: 2011-8-11
 *      Author: q
 */
#include <stdio.h>
#include <android/log.h>
#include <android_gqweb_com_jni_TestJniCall.h>

#define  log_err(str)    __android_log_write(ANDROID_LOG_ERROR,"GqTag",str)
#define  log_info(str)   __android_log_write(ANDROID_LOG_INFO,"GqTag",str)
#define  log_warn(str)    __android_log_write(ANDROID_LOG_WARN,"GqTag",str)

JNICALL jstring Java_android_gqweb_com_jni_TestJniCall_callTestFun(JNIEnv *env, jobject jthis, jstring name)
{
	__android_log_write(ANDROID_LOG_INFO,"GqTag","jni info");
	//log_info("jni info");
	printf("jni printf \r\n");
	return name;
}


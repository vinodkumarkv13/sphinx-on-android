#include <stdio.h>
#include <gqcomm.h>

#include <gqrecordsl.h>
#include <gqandroidsphinx.h>
#include <gqandroidrecordsl.h>
#include <igqsphinx.h>

#include <android_gqweb_net_jni_SphinxJniCall.h>

IGqSphinx *g_psphinx = NULL;
IGqRecord *g_precord = NULL;

jboolean Java_android_gqweb_net_jni_SphinxJniCall_initSphinx(JNIEnv *env,
		jobject jthis) {
	//delete the object if it exist
	Java_android_gqweb_net_jni_SphinxJniCall_destroySphinx(env, jthis);

	g_psphinx = new GqAndroidSphinx;
	g_precord = new GqRecordSL;
	return g_psphinx->init_sphinx(g_precord);
}

jboolean Java_android_gqweb_net_jni_SphinxJniCall_startSphinxRecord(JNIEnv *env,
		jobject jthis) {
	return g_psphinx->start_recognize_from_mic();
}

jboolean Java_android_gqweb_net_jni_SphinxJniCall_stopSphinxRecord(JNIEnv *env,
		jobject jthis) {
	return g_psphinx->end_recognize_from_mic();
}

jboolean Java_android_gqweb_net_jni_SphinxJniCall_destroySphinx(JNIEnv *env,
		jobject jthis) {
	if (g_precord)
		delete g_precord;

	if (g_psphinx)
		delete g_psphinx;
	return true;
}

jstring Java_android_gqweb_net_jni_SphinxJniCall_getSphinxRecognizedStr(
		JNIEnv *env, jobject jthis) {
	std::string srecog = g_psphinx->get_recognized_str();
	return (*env).NewStringUTF(srecog.c_str());
}


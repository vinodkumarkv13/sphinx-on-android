/*
 * gqcomm.h
 *
 *  Created on: 2011-9-7
 *      Author: root
 */

#ifndef GQCOMM_H_
#define GQCOMM_H_

#include <android/log.h>
#ifdef _DEBUG_
#	define LOGE(...) __android_log_print(ANDROID_LOG_ERROR  , "log_gqw", __VA_ARGS__)
#	define LOGV(...) __android_log_print(ANDROID_LOG_VERBOSE, "log_gqw", __VA_ARGS__)
# 	define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG , "log_gqw", __VA_ARGS__)
# 	define LOGI(...) __android_log_print(ANDROID_LOG_INFO  , "log_gqw", __VA_ARGS__)
# 	define LOGW(...) __android_log_print(ANDROID_LOG_WARN  , "log_gqw", __VA_ARGS__)
#else
#	define LOGE(...)
#	define LOGV(...)
# 	define LOGD(...)
# 	define LOGI(...)
# 	define LOGW(...)
#endif /* _DEBUG_ */


#endif /* GQCOMM_H_ */

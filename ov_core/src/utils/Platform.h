//
// Created by vell on 19-2-20.
//

#pragma once

#define IS_DEBUG 1

#if __ANDROID__
#include "android/log.h"

#define S1(x) #x
#define S2(x) S1(x)
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define FILE_TAG (std::string(__FILENAME__) + ":" + std::string(S2(__LINE__))).c_str()

#if IS_DEBUG
#define LOGD(LOG_TAG, ...) __android_log_print(ANDROID_LOG_DEBUG  , LOG_TAG, __VA_ARGS__)
#define LOGV(LOG_TAG, ...) __android_log_print(ANDROID_LOG_VERBOSE, LOG_TAG, __VA_ARGS__)
#define LOGI(LOG_TAG, ...) __android_log_print(ANDROID_LOG_INFO   , LOG_TAG, __VA_ARGS__)
#define LOGW(LOG_TAG, ...) __android_log_print(ANDROID_LOG_WARN   , LOG_TAG, __VA_ARGS__)
#define LOGE(LOG_TAG, ...) __android_log_print(ANDROID_LOG_ERROR  , LOG_TAG, __VA_ARGS__)
#define printf(...) LOGD(FILE_TAG, __VA_ARGS__)
#define TLog(...) LOGD(FILE_LINE, __VA_ARGS__)
#else
#endif // IS_DEBUG

#else

#endif // __ANDROID__

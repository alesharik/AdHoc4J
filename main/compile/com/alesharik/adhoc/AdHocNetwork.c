#ifndef adhoc4j_AdHocNetwork
#define adhoc4j_AdHocNetwork

#include <jni.h>
#include "com_alesharik_adhoc_AdHocNetwork.h"
#include <adhoc.h>

#include "Utils.c"

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_connect(JNIEnv *env, jobject obj, jstring pass, jlong geoId, jboolean saveProfile, jboolean userSpecific) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_deleteProfile(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_disconnect(JNIEnv *env, jobject obj) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getContextGuid(JNIEnv *env, jobject obj) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getInterface(JNIEnv *env, jobject obj) {
}

JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getProfileName(JNIEnv *env, jobject obj) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSecuritySettings(JNIEnv *env, jobject obj) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSignalQuality(JNIEnv *env, jobject obj) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSignature(JNIEnv *env, jobject obj) {
}

JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSSID(JNIEnv *env, jobject obj) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getStatus(JNIEnv *env, jobject obj) {
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocNetwork_hasProfile(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_registerSink(JNIEnv *env, jobject obj, jobject sink) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_unregisterSink(JNIEnv *env, jobject obj, jobject sink) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_init(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_clean(JNIEnv *env, jobject obj) {
}

#endif
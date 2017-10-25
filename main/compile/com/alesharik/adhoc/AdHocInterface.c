#ifndef adhoc4j_AdHocInterface
#define adhoc4j_AdHocInterface

#include <jni.h>
#include "com_alesharik_adhoc_AdHocInterface.h"
#include <adhoc.h>

#include "Utils.c"

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getActiveNetwork(JNIEnv *env, jobject obj) {

}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getDeviceSignature(JNIEnv *env, jobject obj) {
}

JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocInterface_getFriendlyName(JNIEnv *env, jobject obj) {

}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getNetworks(JNIEnv *env, jobject obj) {

}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getSecuritySettings(JNIEnv *env, jobject obj) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getStatus(JNIEnv *env, jobject obj) {
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocInterface_isAdHocSupported(JNIEnv *env, jobject obj) {
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocInterface_isDot11d(JNIEnv *env, jobject obj) {
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocInterface_isRadioOn(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_register(JNIEnv *env, jobject obj, jobject sink) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_unregister(JNIEnv *env, jobject obj, jobject sink) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_clean(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_init(JNIEnv *env, jobject obj) {
}

#endif
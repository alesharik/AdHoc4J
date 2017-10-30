#ifndef adhoc4j_AdHocNetwork
#define adhoc4j_AdHocNetwork

#include "com_alesharik_adhoc_AdHocNetwork.h"
#include <adhoc.h>

#include "Utils.c"

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_connect(JNIEnv *env, jobject obj, jstring pass, jlong geoId, jboolean saveProfile, jboolean userSpecific) {
    IDot11AdHocNetwork *net = getNetwork(env, obj);
    const char* data = (*env)->GetStringUTFChars(env, pass, 0);
    HRESULT hresult = net->Connect(data, geoId, saveProfile, userSpecific);

    (*env)->ReleaseStringUTFChars(env, pass, data);
    handleResult(env, hresult);
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_deleteProfile(JNIEnv *env, jobject obj) {
    handleResult(env, getNetwork(env, obj)->DeleteProfile());
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_disconnect(JNIEnv *env, jobject obj) {
    handleResult(env, getNetwork(env, obj)->Disconnect());
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getContextGuid(JNIEnv *env, jobject obj) {
    GUID *ret;
    handleResult(env, getNetwork(env, obj)->GetContextGuid(ret));
    return createGuid(env, *ret);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getInterface(JNIEnv *env, jobject obj) {
    IDot11AdHocInterface **i;
    handleResult(env, getNetwork(env, obj)->GetInterface(i));
    return createInterface(env, *i);
}

JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getProfileName(JNIEnv *env, jobject obj) {
    char **str;
    handleResult(env, getNetwork(env, obj)->GetProfileName(str));
    return (*env)->NewStringUTF(env, *str);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSecuritySettings(JNIEnv *env, jobject obj) {
    IDot11AdHocSecuritySettings **settings;
    handleResult(env, getNetwork(env, obj)->GetSecuritySetting(settings)));
    return createSecuritySettings(env, *settings);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSignalQuality(JNIEnv *env, jobject obj) {
    long *cur;
    long *max;
    handleResult(env, getNetwork(env, obj)->GetSignalQuality(cur, max)));
    return createSignalQuality(env, *cur, *max);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSignature(JNIEnv *env, jobject obj) {
    GUID *sig;
    handleResult(env, getNetwork(env, obj)->GetSignature(sig)));
    return createGuid(env, *sig);
}

JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSSID(JNIEnv *env, jobject obj) {
    char **str;
    handleResult(env, getNetwork(env, obj)->GetSSID(str));
    return (*env)->NewStringUTF(env, *str);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getStatus(JNIEnv *env, jobject obj) {
    DOT11_ADHOC_NETWORK_CONNECTION_STATUS *status;
    handleResult(env, getNetwork(env, obj)->GetStatus(status));
    return createConnectionStatus(env, *status);
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocNetwork_hasProfile(JNIEnv *env, jobject obj) {
    BOOLEAN *b;
    handleResult(env, getNetwork(env, obj)->HasProfile(b));
    return *b;
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_registerSink(JNIEnv *env, jobject obj, jobject sink) {
    //FIXME
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_unregisterSink(JNIEnv *env, jobject obj, jobject sink) {
    //FIXME
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_init(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_clean(JNIEnv *env, jobject obj) {
}

#endif

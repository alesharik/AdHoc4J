#ifndef adhoc4j_AdHocInterface
#define adhoc4j_AdHocInterface

#include "com_alesharik_adhoc_AdHocInterface.h"
#include <adhoc.h>

#include "Utils.c"

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getActiveNetwork(JNIEnv *env, jobject obj) {
    IDot11AdHocNetwork **net;
    handleResult(env, getInterface(env, obj)->GetActiveNetwork(net));
    return createNetwork(env, *net);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getDeviceSignature(JNIEnv *env, jobject obj) {
    GUID *guid;
    handleResult(env, getInterface(env, obj)->GetDeviceSignature(guid));
    return createGuid(env, *guid);
}

JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocInterface_getFriendlyName(JNIEnv *env, jobject obj) {
    char **str;
    handleResult(env, getInterface(env, obj)->GetFriendlyName(str));
    return (*env)->NewStringUTF(env, *str);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getNetworks(JNIEnv *env, jobject obj) {
    jobject list = createList(env);
    IEnumDot11AdHocNetworks **nets;
    handleResult(env, getInterface(env, obj)->GetIEnumDot11AdHocNetworks(0, nets));
    long *count;
    IDot11AdHocNetwork **netElements;
    do {
        nets->Next(1024, netElements, count);
        for(long i = 0; i < *count; i++) {
            addObject(env, list, createNetwork(env, netElements[i]));
        }
    } while(*count == 1024);
    return list;
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getSecuritySettings(JNIEnv *env, jobject obj) {
    jobject list = createList(env);
    IEnumDot11AdHocSecuritySettings **nets;
    handleResult(env, getInterface(env, obj)->GetIEnumSecuritySettings(nets));
    long *count;
    IDot11AdHocSecuritySettings **netElements;
    do {
        nets->Next(1024, netElements, count);
        for(long i = 0; i < *count; i++) {
            addObject(env, list, createSecuritySettings(env, netElements[i]));
        }
    } while(*count == 1024);
    return list;
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocInterface_getStatus(JNIEnv *env, jobject obj) {
    DOT11_ADHOC_NETWORK_CONNECTION_STATUS *stat;
    handleResult(env, getInterface(env, obj)->GetStatus(stat));
    return createConnectionStatus(env, *stat);
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocInterface_isAdHocSupported(JNIEnv *env, jobject obj) {
    BOOLEAN *b;
    handleResult(env, getInterface(env, obj)->IsAdHocCapable(b));
    return *b;
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocInterface_isDot11d(JNIEnv *env, jobject obj) {
    BOOLEAN *b;
    handleResult(env, getInterface(env, obj)->IsDot11d(b));
    return *b;
}

JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocInterface_isRadioOn(JNIEnv *env, jobject obj) {
    BOOLEAN *b;
    handleResult(env, getInterface(env, obj)->IsRadioOn(b));
    return *b;
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_register(JNIEnv *env, jobject obj, jobject sink) {
    //fixme
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_unregister(JNIEnv *env, jobject obj, jobject sink) {
    //fixme
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_clean(JNIEnv *env, jobject obj) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocInterface_init(JNIEnv *env, jobject obj) {
}

#endif

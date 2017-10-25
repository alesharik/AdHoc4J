#ifndef adhoc4j_AdHocManager
#define adhoc4j_AdHocManager

#include <jni.h>
#include "com_alesharik_adhoc_AdHocManager.h"
#include <adhoc.h>

#include "Utils.c"

static IDot11AdHocManager manager;

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    JNIEnv* env;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    //FIXME get classes before runtime, use global ref
    // Get jclass with env->FindClass.
    // Register methods with env->RegisterNatives.

    return JNI_VERSION_1_6;//TODO check
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_commit(JNIEnv *env, jclass clazz, jobject network, jboolean saveNetwork, jboolean userSpecific) {
    jclass clz = env->GetObjectClass(network);
    jfieldID f = env->GetFieldID(clz, "pointer", "L");
    long netPointer = env->GetLongField(network, f);
    if(netPointer == 0) {
        return NULL;
    }
    HRESULT result = manager.CommitCreatedNetwork((IDot11AdHocNetwork*) netPointer, saveNetwork, userSpecific);
    handleResult(env, result);
    return network;
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_createNetwork(JNIEnv *env, jclass clazz, jstring name, jstring password, jlong geoId, jobject interface, jobject securitySettings, jobject contextGuid) {
    const char* netName = env->GetStringUTFChars(name, 0);
    const char* pass = env->GetStringUTFChars(password, 0);
    IDot11AdHocSecuritySettings *settings = getSettings(env, securitySettings)
    IDot11AdHocInterface *inter = getInterface(env, interface);
    GUID context = getGuid(env, contextGuid);
    IDot11AdHocNetwork **network = 0;
    HRESULT result = manager.CreateNetwork(netName, pass, geoId, inter, settings, context, network);
    handleResult(env, result);

    env->ReleaseStringUTFChars(name, netName);
    env->ReleaseStringUTFChars(password, pass);

    return createNetwork(env, *network);
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getInterfaces(JNIEnv *env, jclass clazz) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getNetworks(JNIEnv *env, jclass clazz) {
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getNetwork(JNIEnv *env, jclass clazz, jobject guid) {

}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocManager_registerSink(JNIEnv *env, jclass clazz, jobject sink) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocManager_unregisterSink(JNIEnv *env, jclass clazz, jobject sink) {
}

#endif
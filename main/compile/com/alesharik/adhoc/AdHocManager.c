#ifndef adhoc4j_AdHocManager
#define adhoc4j_AdHocManager

#include <jni.h>
#include "com_alesharik_adhoc_AdHocManager.h"
#include <adhoc.h>

#include "Utils.c"

static IDot11AdHocManager manager;

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
    jobject list = createList(env);
    IEnumDot11AdHocInterfaces **nets;
    handleResult(env, manager.GetIEnumDot11AdHocInterfaces(nets));
    long *count;
    IDot11AdHocInterface **netElements;
    do {
        nets->Next(1024, netElements, count);
        for(long i = 0; i < *count, i++) {
            addObject(env, list, createInterface(env, netElements[i]));
        }
    } while(*count == 1024);
    return list;
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getNetworks(JNIEnv *env, jclass clazz, jobject guid) {
    jobject list = createList(env);
    GUID g = getGuid(env, guid);
    IEnumDot11AdHocNetworks **nets;
    handleResult(env, manager.GetIEnumDot11AdHocNetworks(g, nets));
    long *count;
    IDot11AdHocNetwork **netElements;
    do {
        nets->Next(1024, netElements, count);
        for(long i = 0; i < *count, i++) {
            addObject(env, list, createNetwork(env, netElements[i]));
        }
    } while(*count == 1024);
    return list;
}

JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getNetwork(JNIEnv *env, jclass clazz, jobject guid) {
    IDot11AdHocNetwork **net;
    GUID g = getGuid(env, guid);
    manager.GetNetwork(&g, net);
    return createNetwork(env, *net);
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocManager_registerSink(JNIEnv *env, jclass clazz, jobject sink) {
}

JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocManager_unregisterSink(JNIEnv *env, jclass clazz, jobject sink) {
}

#endif

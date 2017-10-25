#include <jni.h>
#include <com_alesharik_adhoc_AdHocManager.h>
#include <adhoc.h>

#include "Utils.c"

static IDot11AdHocManager manager;

/*
 * Class:     com_alesharik_adhoc_AdHocManager
 * Method:    commit
 * Signature: (Lcom/alesharik/adhoc/AdHocNetwork;ZZ)Lcom/alesharik/adhoc/AdHocNetwork;
 */
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

/*
 * Class:     com_alesharik_adhoc_AdHocManager
 * Method:    createNetwork
 * Signature: (Ljava/lang/String;Ljava/lang/String;JLcom/alesharik/adhoc/AdHocInterface;Lcom/alesharik/adhoc/security/SecuritySettings;Ljava/util/UUID;)Lcom/alesharik/adhoc/AdHocNetwork;
 */
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

/*
 * Class:     com_alesharik_adhoc_AdHocManager
 * Method:    getInterfaces
 * Signature: ()Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getInterfaces
  (JNIEnv *, jclass);

/*
 * Class:     com_alesharik_adhoc_AdHocManager
 * Method:    getNetworks
 * Signature: ()Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getNetworks
  (JNIEnv *, jclass);

/*
 * Class:     com_alesharik_adhoc_AdHocManager
 * Method:    getNetwork
 * Signature: (Ljava/util/UUID;)Lcom/alesharik/adhoc/AdHocNetwork;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocManager_getNetwork
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocManager
 * Method:    registerSink
 * Signature: (Lcom/alesharik/adhoc/AdHocManager/Sink;)V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocManager_registerSink
  (JNIEnv *, jclass, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocManager
 * Method:    unregisterSink
 * Signature: (Lcom/alesharik/adhoc/AdHocManager/Sink;)V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocManager_unregisterSink
  (JNIEnv *, jclass, jobject);

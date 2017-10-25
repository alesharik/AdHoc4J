/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_alesharik_adhoc_AdHocNetwork */

#ifndef _Included_com_alesharik_adhoc_AdHocNetwork
#define _Included_com_alesharik_adhoc_AdHocNetwork
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    connect
 * Signature: (Ljava/lang/String;JZZ)V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_connect
  (JNIEnv *, jobject, jstring, jlong, jboolean, jboolean);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    deleteProfile
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_deleteProfile
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    disconnect
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_disconnect
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getContextGuid
 * Signature: ()Ljava/util/UUID;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getContextGuid
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getInterface
 * Signature: ()Lcom/alesharik/adhoc/AdHocInterface;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getInterface
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getProfileName
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getProfileName
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getSecuritySettings
 * Signature: ()Lcom/alesharik/adhoc/security/SecuritySettings;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSecuritySettings
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getSignalQuality
 * Signature: ()Lcom/alesharik/adhoc/AdHocNetwork/SignalQuality;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSignalQuality
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getSignature
 * Signature: ()Ljava/util/UUID;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSignature
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getSSID
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getSSID
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    getStatus
 * Signature: ()Lcom/alesharik/adhoc/ConnectionStatus;
 */
JNIEXPORT jobject JNICALL Java_com_alesharik_adhoc_AdHocNetwork_getStatus
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    hasProfile
 * Signature: ()Z
 */
JNIEXPORT jboolean JNICALL Java_com_alesharik_adhoc_AdHocNetwork_hasProfile
  (JNIEnv *, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    registerSink
 * Signature: (Lcom/alesharik/adhoc/AdHocNetwork/Sink;)V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_registerSink
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    unregisterSink
 * Signature: (Lcom/alesharik/adhoc/AdHocNetwork/Sink;)V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_unregisterSink
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    init
 * Signature: (Ljava/util/UUID;)V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_init
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_alesharik_adhoc_AdHocNetwork
 * Method:    clean
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_com_alesharik_adhoc_AdHocNetwork_clean
  (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif

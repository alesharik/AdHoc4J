#ifndef adhoc4j_Utils_h
#define adhoc4j_Utils_h

#include <jni.h>
#define INITGUID
#include <adhoc.h>

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved);

BOOLEAN handleResult(JNIEnv *env, HRESULT result);

long getObjectPointer(JNIEnv *env, jobject obj);

IDot11AdHocSecuritySettings *getSettings(JNIEnv *env, jobject obj);

jobject createCipherAlgorithm(JNIEnv *env, DOT11_ADHOC_CIPHER_ALGORITHM algo);

jobject createAuthAlgorithm(JNIEnv *env, DOT11_ADHOC_AUTH_ALGORITHM algo);

jobject createSecuritySettings(JNIEnv *env, IDot11AdHocSecuritySettings *settings);

IDot11AdHocInterface *getInterface(JNIEnv *env, jobject obj);

jobject createInterface(JNIEnv *env, IDot11AdHocInterface *i);

IDot11AdHocNetwork *getNetwork(JNIEnv *env, jobject obj);

GUID getGuid(JNIEnv *env, jobject obj);

jobject createGuid(JNIEnv *env, GUID obj);

DOT11_ADHOC_CIPHER_ALGORITHM getCipherAlgorithm(JNIEnv *env, jobject type);

DOT11_ADHOC_AUTH_ALGORITHM getAuthAlgorithm(JNIEnv *env, jobject type);

jobject createNetwork(JNIEnv *env, IDot11AdHocNetwork *network);

jobject createSignalQuality(JNIEnv *env, long current, long max);

DOT11_ADHOC_CONNECT_FAIL_REASON getFailReason(JNIEnv *env, jobject o);

jobject createFailReason(JNIEnv *env, DOT11_ADHOC_CONNECT_FAIL_REASON reason);

DOT11_ADHOC_NETWORK_CONNECTION_STATUS getConnectionStatus(JNIEnv *env, jobject o);

jobject createConnectionStatus(JNIEnv *env, DOT11_ADHOC_NETWORK_CONNECTION_STATUS reason);

jobject createList(JNIEnv *env);

void addObject(JNIEnv *env, jobject list, jobject toAdd);

#endif

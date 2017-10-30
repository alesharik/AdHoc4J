#ifndef adhoc4j_Utils
#define adhoc4j_Utils

#include <jni.h>
#include <adhoc.h>

static jclass guidClass;
static jmethodID guidClassCtor;

static jclass cipherAlogrithmClass;
static jmethodID parseCipherAlgorithmMethod;
static jmethodID getCipherAlgorithmMethod;

static jclass authAlogrithmClass;
static jmethodID parseAuthAlgorithmMethod;
static jmethodID getAuthAlgorithmMethod;

static jclass securitySettingsClass;
static jmethodID securitySettingsCtor;

static jclass signalQualityClass;
static jmethodID signalQualityClassCtor;

static jclass failReasonClass;
static jmethodID parseFailReasonMethod;
static jmethodID getFailReasonMethod;

static jclass connectionStatusClass;
static jmethodID parseConnectionStatusMethod;
static jmethodID getConnectionStatusMethod;

static jclass interfaceClass;
static jmethodID interfaceCtor;

static jclass networkClass;
static jmethodID networkCtor;

static jclass listClass;
static jmethodID listCtor;
static jmethodID listAddMethod;

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if ((*vm)->GetEnv(vm, (void **)(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    jclass guid = (*env)->FindClass(env, "com/alesharik/adhoc/Guid");
    guidClass = (*env)->NewGlobalRef(env, guid);
    guidClassCtor = (*env)->GetMethodID(env, guidClass, "<init>", "(ISS[B])V");

    jclass cipher = (*env)->FindClass(env, "com/alesharik/adhoc/security/CipherAlgorithm");
    cipherAlogrithmClass = (*env)->NewGlobalRef(env, cipher);

    parseCipherAlgorithmMethod = (*env)->GetMethodID(env, cipherAlogrithmClass, "getAlgorithm",
                                                  "(I)Lcom/alesharik/adhoc/security/CipherAlgorithm;");
    getCipherAlgorithmMethod = (*env)->GetMethodID(env, cipherAlogrithmClass, "getType", "()I");

    jclass auth = (*env)->FindClass(env, "com/alesharik/adhoc/security/AuthAlgorithm");
    authAlogrithmClass = (*env)->NewGlobalRef(env, auth);

    parseAuthAlgorithmMethod = (*env)->GetMethodID(env, authAlogrithmClass, "getAlgorithm",
                                                "(I)Lcom/alesharik/adhoc/security/CipherAlgorithm;");
    getAuthAlgorithmMethod = (*env)->GetMethodID(env, authAlogrithmClass, "getType", "()I");

    jclass security = (*env)->FindClass(env, "com/alesharik/adhoc/security/SecuritySettings");
    securitySettingsClass = (*env)->NewGlobalRef(env, security);

    securitySettingsCtor = (*env)->GetMethodID(env, securitySettingsClass, "<init>",
                                            "(JLcom/alesharik/adhoc/security/CipherAlgorithm;Lcom/alesharik/adhoc/security/CipherAlgorithm;)V");

    jclass signal = (*env)->FindClass(env, "com/alesharik/adhoc/AdHocNetwork$SignalQuality");
    signalQualityClass = (*env)->NewGlobalRef(env, signal);

    signalQualityClassCtor = (*env)->GetMethodID(env, signalQualityClass, "<init>", "(JJ)V");

    jclass failReason = (*env)->FindClass(env, "com/alesharik/adhoc/ConnectionFailedReason");
    failReasonClass = (*env)->NewGlobalRef(env, failReason);
    parseFailReasonMethod = (*env)->GetMethodID(env, failReasonClass, "getReason",
                                             "(I)Lcom/alesharik/adhoc/ConnectionFailedReason;");
    getFailReasonMethod = (*env)->GetMethodID(env, failReasonClass, "getType", "()I");

    jclass connectionStatus = (*env)->FindClass(env, "com/alesharik/adhoc/ConnectionFailedReason");
    connectionStatusClass = (*env)->NewGlobalRef(env, connectionStatus);
    parseConnectionStatusMethod = (*env)->GetMethodID(env, connectionStatusClass, "getReason",
                                                   "(I)Lcom/alesharik/adhoc/ConnectionStatus;");
    getConnectionStatusMethod = (*env)->GetMethodID(env, connectionStatusClass, "getType", "()I");

    jclass inter = (*env)->FindClass(env, "com/alesharik/adhoc/AdHocInterface");
    interfaceClass = (*env)->NewGlobalRef(env, inter);
    interfaceCtor = (*env)->GetMethodID(env, interfaceClass, "<init>", "(J)V");

    jclass net = (*env)->FindClass(env, "com/alesharik/adhoc/AdHocNetwork");
    networkClass = (*env)->NewGlobalRef(env, net);
    networkCtor = (*env)->GetMethodID(env, networkClass, "<init>", "(J)V");

    jclass list = (*env)->FindClass(env, "java/util/ArrayList");
    listClass = (*env)->NewGlobalRef(env, list);
    listCtor = (*env)->GetMethodID(env, listClass, "<init>", "()V");
    listAddMethod = (*env)->GetMethodID(env, listClass, "add", "(Ljava/lang/Object;)Z");

    return JNI_VERSION_1_8;
}

BOOLEAN handleResult(JNIEnv *env, HRESULT result) {
    if (result == S_OK) {
        return 1;
    }

    jclass except = (*env)->FindClass(env, "java/lang/IllegalStateException");
    char str[21];
    sprintf((char *) &str, "%d", (int) result);
    (*env)->ThrowNew(env, except, str);
    return 0;
}

long getObjectPointer(JNIEnv *env, jobject obj) {
    jfieldID id = (*env)->GetFieldID(env, (*env)->GetObjectClass(env, obj), "pointer", "J");
    return (*env)->GetLongField(env, obj, id);
}

IDot11AdHocSecuritySettings *getSettings(JNIEnv *env, jobject obj) {
    return (IDot11AdHocSecuritySettings *) getObjectPointer(env, obj);
}

jobject createCipherAlgorithm(JNIEnv *env, DOT11_ADHOC_CIPHER_ALGORITHM algo) {
    return (*env)->CallStaticObjectMethod(env, cipherAlogrithmClass, parseCipherAlgorithmMethod, (jint) algo);
}

jobject createAuthAlgorithm(JNIEnv *env, DOT11_ADHOC_AUTH_ALGORITHM algo) {
    return (*env)->CallStaticObjectMethod(env, authAlogrithmClass, parseAuthAlgorithmMethod, (jint) algo);
}

jobject createSecuritySettings(JNIEnv *env, IDot11AdHocSecuritySettings *settings) {
    DOT11_ADHOC_AUTH_ALGORITHM *alg;
    handleResult(env, settings->GetDot11AuthAlgorithm(alg));
    DOT11_ADHOC_CIPHER_ALGORITHM *cipher;
    handleResult(env, settings->GetDot11CipherAlgorithm(cipher));
    return (*env)->NewObject(env, securitySettingsClass, securitySettingsCtor, (jlong) settings, createAuthAlgorithm(env, *alg),
                          createCipherAlgorithm(env, *cipher));
}

IDot11AdHocInterface *getInterface(JNIEnv *env, jobject obj) {
    return (IDot11AdHocInterface *) getObjectPointer(env, obj);
}

jobject createInterface(JNIEnv *env, IDot11AdHocInterface *i) {
    return (*env)->NewObject(env, interfaceClass, interfaceCtor, (jlong) i);
}

IDot11AdHocNetwork *getNetwork(JNIEnv *env, jobject obj) {
    return (IDot11AdHocNetwork *) getObjectPointer(env, obj);
}

GUID getGuid(JNIEnv *env, jobject obj) {
    GUID guid;
    jclass clazz = (*env)->GetObjectClass(env, obj);
    guid.Data1 = (unsigned long) (*env)->GetIntField(env, obj, (*env)->GetFieldID(env, clazz, "dword", "I"));
    guid.Data2 = (unsigned short) (*env)->GetShortField(env, obj, (*env)->GetFieldID(env, clazz, "word1", "S"));
    guid.Data3 = (unsigned short) (*env)->GetShortField(env, obj, (*env)->GetFieldID(env, clazz, "word2", "S"));
    jbyteArray arr = (jbyteArray)((*env)->GetObjectField(env, obj, (*env)->GetFieldID(env, clazz, "data", "[B")));
    const jbyte *dat = (*env)->GetByteArrayElements(env, arr, 0);
    for (int i = 0; i < 8; i++) {
        guid.Data4[i] = (unsigned char) dat[i];
    }
    (*env)->ReleaseByteArrayElements(env, arr, (jbyte *) dat, 0);
    return guid;
}

jobject createGuid(JNIEnv *env, GUID obj) {
    jbyteArray arr = (*env)->NewByteArray(env, 8);
    jbyte *elem = (*env)->GetByteArrayElements(env, arr, 0);
    for (int i = 0; i < 8; i++) {
        elem[i] = obj.Data4[i];
    }
    (*env)->ReleaseByteArrayElements(env, arr, elem, 0);
    return (*env)->NewObject(env, guidClass, guidClassCtor, obj.Data1, obj.Data2, obj.Data3, arr);
}

DOT11_ADHOC_CIPHER_ALGORITHM getCipherAlgorithm(JNIEnv *env, jobject type) {
    return (DOT11_ADHOC_CIPHER_ALGORITHM) (*env)->CallIntMethod(env, type, getCipherAlgorithmMethod);
}

DOT11_ADHOC_AUTH_ALGORITHM getAuthAlgorithm(JNIEnv *env, jobject type) {
    return (DOT11_ADHOC_AUTH_ALGORITHM) (*env)->CallIntMethod(env, type, getAuthAlgorithmMethod);
}

jobject createNetwork(JNIEnv *env, IDot11AdHocNetwork *network) {
    return (*env)->NewObject(env, networkClass, networkCtor, (jlong) network);
}

jobject createSignalQuality(JNIEnv *env, long current, long max) {
    return (*env)->NewObject(env, signalQualityClass, signalQualityClassCtor, current, max);
}

DOT11_ADHOC_CONNECT_FAIL_REASON getFailReason(JNIEnv *env, jobject o) {
    return (DOT11_ADHOC_CONNECT_FAIL_REASON) (*env)->CallIntMethod(env, o, getFailReasonMethod);
}

jobject createFailReason(JNIEnv *env, DOT11_ADHOC_CONNECT_FAIL_REASON reason) {
    return (*env)->CallStaticObjectMethod(env, failReasonClass, parseFailReasonMethod, (jint) reason);
}

DOT11_ADHOC_NETWORK_CONNECTION_STATUS getConnectionStatus(JNIEnv *env, jobject o) {
    return (DOT11_ADHOC_NETWORK_CONNECTION_STATUS) (*env)->CallIntMethod(env, o, getConnectionStatusMethod);
}

jobject createConnectionStatus(JNIEnv *env, DOT11_ADHOC_NETWORK_CONNECTION_STATUS reason) {
    return (*env)->CallStaticObjectMethod(env, connectionStatusClass, parseConnectionStatusMethod, (jint) reason);
}

jobject createList(JNIEnv *env) {
    return (*env)->NewObject(env, listClass, listCtor);
}

void addObject(JNIEnv *env, jobject list, jobject toAdd) {
    (*env)->CallBooleanMethod(env, list, listAddMethod, toAdd);
}

#endif

#ifndef adhoc4j_Utils
#define adhoc4j_Utils

#include <jni.h>
#include <Utils.h>

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

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env;
    if (vm->GetEnv((void **)(&env), JNI_VERSION_1_6) != JNI_OK) {
        return -1;
    }

    jclass guid = env->FindClass("com/alesharik/adhoc/Guid");
    guidClass = (jclass) env->NewGlobalRef((jobject) guid);
    guidClassCtor = env->GetMethodID(guidClass, "<init>", "(ISS[B])V");

    jclass cipher = env->FindClass("com/alesharik/adhoc/security/CipherAlgorithm");
    cipherAlogrithmClass = (jclass) env->NewGlobalRef((jobject) cipher);

    parseCipherAlgorithmMethod = env->GetMethodID(cipherAlogrithmClass, "getAlgorithm",
                                                  "(I)Lcom/alesharik/adhoc/security/CipherAlgorithm;");
    getCipherAlgorithmMethod = env->GetMethodID(cipherAlogrithmClass, "getType", "()I");

    jclass auth = env->FindClass("com/alesharik/adhoc/security/AuthAlgorithm");
    authAlogrithmClass = (jclass) env->NewGlobalRef((jobject) auth);

    parseAuthAlgorithmMethod = env->GetMethodID(authAlogrithmClass, "getAlgorithm",
                                                "(I)Lcom/alesharik/adhoc/security/CipherAlgorithm;");
    getAuthAlgorithmMethod = env->GetMethodID(authAlogrithmClass, "getType", "()I");

    jclass security = env->FindClass("com/alesharik/adhoc/security/SecuritySettings");
    securitySettingsClass = (jclass) env->NewGlobalRef((jobject) security);

    securitySettingsCtor = env->GetMethodID(securitySettingsClass, "<init>",
                                            "(JLcom/alesharik/adhoc/security/CipherAlgorithm;Lcom/alesharik/adhoc/security/CipherAlgorithm;)V");

    jclass signal = env->FindClass("com/alesharik/adhoc/AdHocNetwork$SignalQuality");
    signalQualityClass = (jclass) env->NewGlobalRef((jobject) signal);

    signalQualityClassCtor = env->GetMethodID(signalQualityClass, "<init>", "(JJ)V");

    jclass failReason = env->FindClass("com/alesharik/adhoc/ConnectionFailedReason");
    failReasonClass = (jclass) env->NewGlobalRef((jobject) failReason);
    parseFailReasonMethod = env->GetMethodID(failReasonClass, "getReason",
                                             "(I)Lcom/alesharik/adhoc/ConnectionFailedReason;");
    getFailReasonMethod = env->GetMethodID(failReasonClass, "getType", "()I");

    jclass connectionStatus = env->FindClass("com/alesharik/adhoc/ConnectionFailedReason");
    connectionStatusClass = (jclass) env->NewGlobalRef((jobject) connectionStatus);
    parseConnectionStatusMethod = env->GetMethodID(connectionStatusClass, "getReason",
                                                   "(I)Lcom/alesharik/adhoc/ConnectionStatus;");
    getConnectionStatusMethod = env->GetMethodID(connectionStatusClass, "getType", "()I");

    jclass inter = env->FindClass("com/alesharik/adhoc/AdHocInterface");
    interfaceClass = (jclass) env->NewGlobalRef((jobject) inter);
    interfaceCtor = env->GetMethodID(interfaceClass, "<init>", "(J)V");

    jclass net = env->FindClass("com/alesharik/adhoc/AdHocNetwork");
    networkClass = (jclass) env->NewGlobalRef((jobject) net);
    networkCtor = env->GetMethodID(networkClass, "<init>", "(J)V");

    jclass list = env->FindClass("java/util/ArrayList");
    listClass = (jclass) env->NewGlobalRef((jobject) list);
    listCtor = env->GetMethodID(listClass, "<init>", "()V");
    listAddMethod = env->GetMethodID(listClass, "add", "(Ljava/lang/Object;)Z");

    return JNI_VERSION_1_8;
}

BOOLEAN handleResult(JNIEnv *env, HRESULT result) {
    if (result == S_OK) {
        return 1;
    }

    jclass except = env->FindClass("java/lang/IllegalStateException");
    char str[21];
    sprintf((char *) &str, "%d", (int) result);
    env->ThrowNew(except, str);
    return 0;
}

long getObjectPointer(JNIEnv *env, jobject obj) {
    jfieldID id = env->GetFieldID(env->GetObjectClass(obj), "pointer", "J");
    return env->GetLongField(obj, id);
}

IDot11AdHocSecuritySettings *getSettings(JNIEnv *env, jobject obj) {
    return (IDot11AdHocSecuritySettings *) getObjectPointer(env, obj);
}

jobject createCipherAlgorithm(JNIEnv *env, DOT11_ADHOC_CIPHER_ALGORITHM algo) {
    return env->CallStaticObjectMethod(cipherAlogrithmClass, parseCipherAlgorithmMethod, (jint) algo);
}

jobject createAuthAlgorithm(JNIEnv *env, DOT11_ADHOC_AUTH_ALGORITHM algo) {
    return env->CallStaticObjectMethod(authAlogrithmClass, parseAuthAlgorithmMethod, (jint) algo);
}

jobject createSecuritySettings(JNIEnv *env, IDot11AdHocSecuritySettings *settings) {
    DOT11_ADHOC_AUTH_ALGORITHM *alg;
    handleResult(env, settings->GetDot11AuthAlgorithm(alg));
    DOT11_ADHOC_CIPHER_ALGORITHM *cipher;
    handleResult(env, settings->GetDot11CipherAlgorithm(cipher));
    return env->NewObject(securitySettingsClass, securitySettingsCtor, (jlong) settings, createAuthAlgorithm(env, *alg),
                          createCipherAlgorithm(env, *cipher));
}

IDot11AdHocInterface *getInterface(JNIEnv *env, jobject obj) {
    return (IDot11AdHocInterface *) getObjectPointer(env, obj);
}

jobject createInterface(JNIEnv *env, IDot11AdHocInterface *i) {
    return env->NewObject(interfaceClass, interfaceCtor, (jlong) i);
}

IDot11AdHocNetwork *getNetwork(JNIEnv *env, jobject obj) {
    return (IDot11AdHocNetwork *) getObjectPointer(env, obj);
}

GUID getGuid(JNIEnv *env, jobject obj) {
    GUID guid;
    jclass clazz = env->GetObjectClass(obj);
    guid.Data1 = (unsigned long) env->GetIntField(obj, env->GetFieldID(clazz, "dword", "I"));
    guid.Data2 = (unsigned short) env->GetShortField(obj, env->GetFieldID(clazz, "word1", "S"));
    guid.Data3 = (unsigned short) env->GetShortField(obj, env->GetFieldID(clazz, "word2", "S"));
    jbyteArray arr = (jbyteArray)(env->GetObjectField(obj, env->GetFieldID(clazz, "data", "[B")));
    const jbyte *dat = env->GetByteArrayElements(arr, 0);
    for (int i = 0; i < 8; i++) {
        guid.Data4[i] = (unsigned char) dat[i];
    }
    env->ReleaseByteArrayElements(arr, (jbyte *) dat, 0);
    return guid;
}

jobject createGuid(JNIEnv *env, GUID obj) {
    jbyteArray arr = env->NewByteArray(8);
    jbyte *elem = env->GetByteArrayElements(arr, 0);
    for (int i = 0; i < 8; i++) {
        elem[i] = obj.Data4[i];
    }
    env->ReleaseByteArrayElements(arr, elem, 0);
    return env->NewObject(guidClass, guidClassCtor, obj.Data1, obj.Data2, obj.Data3, arr);
}

DOT11_ADHOC_CIPHER_ALGORITHM getCipherAlgorithm(JNIEnv *env, jobject type) {
    return (DOT11_ADHOC_CIPHER_ALGORITHM) env->CallIntMethod(type, getCipherAlgorithmMethod);
}

DOT11_ADHOC_AUTH_ALGORITHM getAuthAlgorithm(JNIEnv *env, jobject type) {
    return (DOT11_ADHOC_AUTH_ALGORITHM) env->CallIntMethod(type, getAuthAlgorithmMethod);
}

jobject createNetwork(JNIEnv *env, IDot11AdHocNetwork *network) {
    return env->NewObject(networkClass, networkCtor, (jlong) network);
}

jobject createSignalQuality(JNIEnv *env, long current, long max) {
    return env->NewObject(signalQualityClass, signalQualityClassCtor, current, max);
}

DOT11_ADHOC_CONNECT_FAIL_REASON getFailReason(JNIEnv *env, jobject o) {
    return (DOT11_ADHOC_CONNECT_FAIL_REASON) env->CallIntMethod(o, getFailReasonMethod);
}

jobject createFailReason(JNIEnv *env, DOT11_ADHOC_CONNECT_FAIL_REASON reason) {
    return env->CallStaticObjectMethod(failReasonClass, parseFailReasonMethod, (jint) reason);
}

DOT11_ADHOC_NETWORK_CONNECTION_STATUS getConnectionStatus(JNIEnv *env, jobject o) {
    return (DOT11_ADHOC_NETWORK_CONNECTION_STATUS) env->CallIntMethod(o, getConnectionStatusMethod);
}

jobject createConnectionStatus(JNIEnv *env, DOT11_ADHOC_NETWORK_CONNECTION_STATUS reason) {
    return env->CallStaticObjectMethod(connectionStatusClass, parseConnectionStatusMethod, (jint) reason);
}

jobject createList(JNIEnv *env) {
    return env->NewObject(listClass, listCtor);
}

void addObject(JNIEnv *env, jobject list, jobject toAdd) {
    env->CallBooleanMethod(list, listAddMethod, toAdd);
}

#endif

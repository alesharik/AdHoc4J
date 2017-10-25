#ifndef adhoc4j_Utils
#define adhoc4j_Utils

#include <jni.h>
#include <adhoc.h>

void handleResult(JNIEnv *env, HRESULT result) {
    if(result == S_OK) {
        return;
    } else {
        jclass except = env->FindClass("java/lang/IllegalStateExcpetion");
        char str[21];
        sprintf(&str, "%d", result);
        env->ThrowNew(except, str);
    }
}

long getObjectPointer(JNIEnv *env, jobject obj) {
    jfieldID id = env->GetFieldID(env->GetObjectClass(obj), "pointer", "L");
    return env->GetLongField(obj, id);
}

IDot11AdHocSecuritySettings *getSettings(JNIEnv *env, jobject obj) {
    return (IDot11AdHocSecuritySettings*)getObjectPointer(env, obj);
}

IDot11AdHocInterface *getInterface(JNIEnv *env, jobject obj) {
    return (IDot11AdHocInterface*) getObjectPointer(env, obj);
}

IDot11AdHocNetwork *getNetwork(JNIEnv *env, jobject obj) {
    return (IDot11AdHocNetwork*) getObjectPointer(env, obj);
}

GUID getGuid(JNIEnv *env, jobject obj) {
    GUID guid;
    jclass clazz = env->GetObjectClass(obj);
    guid.Data1 = env->GetLongField(obj, env->GetFieldID(clazz, "dword", "L"));
    guid.Data2 = env->GetShortField(obj, env->GetFieldID(clazz, "word1", "S"));
    guid.Data3 = env->GetShortField(obj, env->GetFieldID(clazz, "word2", "S"));
    jcharArray arr = reinterpret_cast<jcharArray>(env->GetObjectField(obj, env->GetFieldID(clazz, "data", "[D")));
    const char* dat = env->GetCharArrayElements(arr, 0);
    for(int i = 0; i < 8; i++) {
        guid.Data4[i] = dat[i];
    }
    env->ReleaseCharArrayElements(arr, dat, 0);
    return guid;
}

jobject createNetwork(JNIEnv *env, IDot11AdHocNetwork *network) {
    jclass clazz = env->FindClass("com/alesharik/adhoc/AdHocNetwork");
    jmethodID c = env->GetMethodID(clazz, "<init>", "(L)V");
    return env->NewObject(clazz, c, (jlong) network);
}

#endif

////
//// Created by leera on 2023/3/17.
////
//
#include "api.h"
#include "../function/function.h"
#include "vector"
#include "string"
#include "cstring"

using namespace std;

struct cpyRet {
    char *dataList[20000];
    int dataNum;
    int dataRes;
};

struct cpyRetTwo {
    char *dataList[20000][1000];
    int dataNumOne[20000];
    int dataNumTwo;
    int dataRes;
};

extern "C" __declspec(dllexport)
cpyRetTwo *gen_chains_all_cpy(char **words, int len) {
    vector<vector<string>> result;
    auto *retResult = (cpyRetTwo *) malloc(sizeof(cpyRetTwo));
    int size = gen_chains_all(words, len, result);
    retResult->dataNumTwo = result.size();
    retResult->dataRes = size;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < result[i].size(); j++) {
            retResult->dataList[i][j] = (char *) result[i][j].c_str();
        }
        retResult->dataNumOne[i] = result[i].size();
    }
    return retResult;
}


extern "C" __declspec(dllexport)
cpyRet *
gen_chain_word_cpy(char **words, int len, char head, char tail, char reject, bool en_loop) {
    vector<string> result;
    auto *retResult = (cpyRet *) malloc(sizeof(cpyRet));
    int size = gen_chain_word(words, len, result, head, tail, reject, en_loop);
    retResult->dataNum = result.size();
    retResult->dataRes = size;
    for (int i = 0; i < size; i++) {
        retResult->dataList[i] = (char *) result[i].c_str();
    }
    return retResult;
}

extern "C" __declspec(dllexport)
cpyRet *gen_chain_char_cpy(char **words, int len, char head, char tail, char reject, bool en_loop) {
    vector<string> result;
    auto *retResult = (cpyRet *) malloc(sizeof(cpyRet));
    int size = gen_chain_char(words, len, result, head, tail, reject, en_loop);
    retResult->dataNum = result.size();
    retResult->dataRes = size;
    for (int i = 0; i < size; i++) {
        retResult->dataList[i] = (char *) result[i].c_str();
    }

    return retResult;
}

//
//#include "jni.h"
//#ifdef __cplusplus
//extern "C" {
//#endif
//// 提供给GUI界面的接口
//JNIEXPORT jint JNICALL
//Java_CoreAPI_genChainsAll(JNIEnv *env, jobject obj, jobjectArray jWords, jint len, jobjectArray jResult) {
//    // 将java的数据类型转化成C++的
//    vector<string> words;
//    for (int i = 0; i < len; i++) {
//        jstring jWord = (jstring) env->GetObjectArrayElement(jWords, i);
//        const char *cWord = env->GetStringUTFChars(jWord, 0);
//        words.emplace_back(cWord);
//        env->ReleaseStringUTFChars(jWord, cWord);
//    }
//    vector<vector<string>> result;
//
//    // 执行C++的对应函数
//    Core core = *new Core(words, len);
//    if (core.checkIllegalLoop()) return (jint) -1;
//    int dllReturnCode = core.genAllWordChain(result);
//
//    // 将C++的数据类型转化成java的
//    int result_size = (int) result.size();
//    for (int i = 0; i < result_size; i++) {
//        int result_i_size = (int) result[i].size();
//        jobjectArray jRow = env->NewObjectArray(result_i_size, env->FindClass("java/lang/String"), NULL);
//        for (int j = 0; j < result_i_size; j++) {
//            env->SetObjectArrayElement(jRow, j, env->NewStringUTF(result[i][j].c_str()));
//        }
//        env->SetObjectArrayElement(jResult, i, jRow);
//    }
//
//    // 返回
//    return (jint) dllReturnCode;
//}
//
//JNIEXPORT jint JNICALL
//Java_CoreAPI_genChainWord(JNIEnv *env, jobject obj, jobjectArray jWords, jint len, jobjectArray jResult, jchar head,
//                          jchar tail, jchar reject, jboolean enable_loop) {
//    // Convert Java objects to C++ data types
//    std::vector<std::string> words;
//    for (int i = 0; i < len; i++) {
//        jstring jWord = (jstring) env->GetObjectArrayElement(jWords, i);
//        const char *cWord = env->GetStringUTFChars(jWord, 0);
//        words.emplace_back(cWord);
//        env->ReleaseStringUTFChars(jWord, cWord);
//    }
//    std::vector<std::string> result;
//
//    // Call your DLL function with the converted data types
//    Core core = *new Core(words, len, enable_loop, (char) head, (char) tail, (char) reject, false);
//    if (core.checkIllegalLoop()) return (jint) -1;
//    int dllReturnCode = gen_chain_word(words, len, result, (char) head, (char) tail, (char) reject, enable_loop);
//
//    // Convert the C++ data types to Java objects
//    for (int i = 0; i < (int )result.size(); i++) {
//        jstring jResultItem = env->NewStringUTF(result[i].c_str());
//        env->SetObjectArrayElement(jResult, i, jResultItem);
//    }
//
//    // Return the DLL return code
//    return (jint) dllReturnCode;
//}
//
//JNIEXPORT jint JNICALL
//Java_CoreAPI_genChainChar(JNIEnv *env, jobject obj, jobjectArray jWords, jint len, jobjectArray jResult, jchar head,
//                          jchar tail, jchar reject, jboolean enable_loop) {
//    // Convert Java objects to C++ data types
//    std::vector<std::string> words;
//    for (int i = 0; i < len; i++) {
//        jstring jWord = (jstring) env->GetObjectArrayElement(jWords, i);
//        const char *cWord = env->GetStringUTFChars(jWord, 0);
//        words.emplace_back(cWord);
//        env->ReleaseStringUTFChars(jWord, cWord);
//    }
//    std::vector<std::string> result;
//
//    // Call your DLL function with the converted data types
//    Core core = *new Core(words, len, enable_loop, (char) head, (char) tail, (char) reject, false);
//    if (core.checkIllegalLoop()) return (jint) -1;
//    int dllReturnCode = gen_chain_char(words, len, result, (char) head, (char) tail, (char) reject, enable_loop);
//
//    // Convert the C++ data types to Java objects
//    for (int i = 0; i < (int )result.size(); i++) {
//        jstring jResultItem = env->NewStringUTF(result[i].c_str());
//        env->SetObjectArrayElement(jResult, i, jResultItem);
//    }
//
//    // Return the DLL return code
//    return (jint) dllReturnCode;
//}
//
//#ifdef __cplusplus
//}
//#endif
//
// Created by leera on 2023/3/17.
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

extern "C" __declspec(dllexport)
cpyRet *gen_chains_all_cpy(char **words, int len) {
    vector<vector<string>> result;
    auto *retResult = (cpyRet *) malloc(sizeof(cpyRet));
    int size = gen_chains_all(words, len, result);
    retResult->dataRes = size;

    for (int i = 0; i < size; i++) {
        string string1;
        for (auto &j: result[i]) {
            string1 += j + " ";
        }
        retResult->dataList[i] = (char *) string1.c_str();
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
//
// Created by leera on 2023/3/17.
//

#include "api.h"
#include "../function/function.h"
#include "vector"
#include "string"
#include "cstring"

using namespace std;

struct cpyRetOneDim {
    char *dataList[2000];
    int dataNum;
    int result;
};

struct cpyRetTwoDim {
    char *dataList[2000][1000];
    int dataNumOne[2000];
    int dataNumTwo;
};

extern "C" __declspec(dllexport)
cpyRetTwoDim *gen_chains_all_cpy(char **words, int len) {
    vector<vector<string>> result;
    auto *retResult = (cpyRetTwoDim *) malloc(sizeof(cpyRetTwoDim));
    int size = gen_chains_all(words, len, result);
    retResult->dataNumTwo = size;
    for (int i = 0; i < size; i++) {
        retResult->dataNumOne[i] = result[i].size();
        for (int j = 0; j < result[i].size(); j++) {
//            retResult->dataList[i][j] = result[i][j].c_str();
            strcpy(retResult->dataList[i][j], result[i][j].c_str());
        }
    }
    return retResult;
}


extern "C" __declspec(dllexport)
cpyRetOneDim *
gen_chain_word_cpy(char **words, int len, char head, char tail, char reject, bool en_loop) {
    vector<string> result;
    auto *retResult = (cpyRetOneDim *) malloc(sizeof(cpyRetOneDim));
    int size = gen_chain_word(words, len, result, head, tail, reject, en_loop);
    retResult->dataNum = result.size();
    retResult->result = size;
    for (int i = 0; i < size; i++) {
        retResult->dataList[i] = (char *) result[i].c_str();
    }

//    auto *retResult = (cpyRetOneDim *) malloc(sizeof(cpyRetOneDim));
//    for (int i = 0; i < len; i++) {
//        retResult->dataList[i] = *(words + i);
//    }
//    retResult->dataNum = len;
//    retResult->result = len;
    return retResult;
}

extern "C" __declspec(dllexport)
cpyRetOneDim *gen_chain_char_cpy(char **words, int len, char head, char tail, char reject, bool en_loop) {
    vector<string> result;
    auto *retResult = (cpyRetOneDim *) malloc(sizeof(cpyRetOneDim));
    int size = gen_chain_char(words, len, result, head, tail, reject, en_loop);
    retResult->dataNum = result.size();
    retResult->result = size;
    for (int i = 0; i < size; i++) {
        retResult->dataList[i] = (char *) result[i].c_str();
    }

    return retResult;
}

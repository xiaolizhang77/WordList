//
// Created by leera on 2023/3/17.
//

#include "api.h"
#include "vector"
#include "string"

using namespace std;

struct cpyRetOneDim {
    const char *dataList[10000];
    int dataNum;
};

struct cpyRetTwoDim {
    const char *dataList[1000][1000];
    int dataNumOne[1000];
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
            retResult->dataList[i][j] = result[i][j].c_str();
        }
    }
    return retResult;
}


extern "C" __declspec(dllexport)
cpyRetOneDim *gen_chain_word_cpy(char **words, int len, char head, char tail, char reject, bool en_loop) {
    vector<string> result;
    auto *retResult = (cpyRetOneDim *) malloc(sizeof(cpyRetOneDim));
    int size = gen_chain_word(words, len, result, head, tail, reject, en_loop);
    retResult->dataNum = size;
    for (int i = 0; i < size; i++) {
        retResult->dataList[i] = result[i].c_str();
    }
    return retResult;
}

extern "C" __declspec(dllexport)
cpyRetOneDim *gen_chain_char_cpy(char **words, int len, char head, char tail, char reject, bool en_loop) {
    vector<string> result;
    auto *retResult = (cpyRetOneDim *) malloc(sizeof(cpyRetOneDim));
    int size = gen_chain_char(words, len, result, head, tail, reject, en_loop);
    retResult->dataNum = size;
    for (int i = 0; i < size; i++) {
        retResult->dataList[i] = result[i].c_str();
    }
    return retResult;
}

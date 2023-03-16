#include "function.h"
#include "bits/stdc++.h"
#include <vector>

using namespace std;

__declspec(dllexport)
int gen_chains_all(char *words[], int len, vector<vector<string>> &result) {
    function1(words, &len, '\0', '\0', '\0', result);
    return result.size();
}

__declspec(dllexport)
int
gen_chain_word(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop) {
    if (enable_loop) {
        int maxLen;
        searchUseInApi(words, len, head, tail, reject, 0, result, &maxLen);
        return maxLen;
    } else {
        function2(words, &len, reject, head, tail, result);
        return result.size();
    }
}


__declspec(dllexport)
int
gen_chain_char(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop) {
    if (enable_loop) {
        int maxLen;
        searchUseInApi(words, len, head, tail, reject, 1, result, &maxLen);
        return maxLen;
    } else {
        function3(words, &len, reject, head, tail, result);
        return result.size();
    }
}


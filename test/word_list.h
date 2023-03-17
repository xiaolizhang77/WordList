#ifndef WORD_LIST_H
#define WORD_LIST_H

// 如果你的编译器是Visual Studio，请使用以下导入导出宏
#ifdef _MSC_VER
    #ifdef WORD_LIST_EXPORTS
            #define WORD_LIST_API __declspec(dllexport)
        #else
            #define WORD_LIST_API __declspec(dllimport)
        #endif
    // 其他编译器请使用以下导入导出宏
#else
    #define WORD_LIST_API
#endif

#include <string>
#include <vector>

#include "iostream"
#include "string"
#include "vector"

using namespace std;
// 如果libword_list.dll中还有其他导出的函数，请在此处声明它们
// 示例：
WORD_LIST_API int gen_chains_all(char *words[], int len, vector<vector<string>> &result);

WORD_LIST_API int
gen_chain_word(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop);

WORD_LIST_API int
gen_chain_char(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop);

char **readWordsFromFile(const char *filename, int *numWords);

#endif // WORD_LIST_H

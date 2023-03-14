//
// Created by Lenovo on 2023/3/5.
//

#ifndef SOFTWARE_ENGINEERING_FUNCTION_H
#define SOFTWARE_ENGINEERING_FUNCTION_H

#include "bits/stdc++.h"

using namespace std;

void longest_chain(int edge[26][26], int *length, char *nodes);

void longest_chain_char(int edge[26][26], int *length, char *nodes);

bool detectCycle(int v, int edge[26][26], bool visited[26], bool recStack[26]);

bool hasCycle(int edge[26][26]);

char **readWordsFromFile(const char *filename, int *numWords);

void getFirstLastChar(char *str, char *first, char *last);

void function2(char **words, const int *nword, char notAppear, char first, char last, vector<string> &result);

void function3(char **words, const int *nword, char notAppear, char first, char last, vector<string> &result);

void function1(char **words, const int *nword, char notAppear, char first, char last, vector<vector<string>> &chain);

void function2And4(int edge[26][26], char first, char last, int *n, int *answer);

void function3And4(int edge[26][26], char first, char last, int *n, int *answer, int *nLength);

struct wordPoint {
    char *s;
    struct wordPoint *next;
};
struct wordsList {
    char first;
    char last;
    struct wordPoint *headWord;
};

typedef struct point {
    char *word;
    int num;
    int flag;
} point;

typedef struct charPoint {
    struct point *t;
    struct charPoint *prev;
} charPoint;

void search(const char *filename, char para_h, char para_t, char para_j, int type, charPoint **lastPoint, int *max);

#endif //SOFTWARE_ENGINEERING_FUNCTION_H

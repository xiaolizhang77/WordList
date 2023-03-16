//
// Created by leera on 2023/3/16.
//
#include "iostream"
#include "string"
#include "vector"

using namespace std;

#ifndef WORDLIST_API_H
#define WORDLIST_API_H

int gen_chains_all(char *words[], int len, vector<vector<string>> &result);

int
gen_chain_word(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop);

int
gen_chain_char(char *words[], int len, vector<string> &result, char head, char tail, char reject, bool enable_loop);


#endif //WORDLIST_API_H

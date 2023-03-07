//
// Created by Lenovo on 2023/3/5.
//

#ifndef SOFTWARE_ENGINEERING_FUNCTION_H
#define SOFTWARE_ENGINEERING_FUNCTION_H

void longest_chain(int edge[26][26], int *length, char *nodes);
void longest_chain_char(int edge[26][26], int *length, char *nodes);
bool detectCycle(int v, int edge[26][26], bool visited[26], bool recStack[26]);
bool hasCycle(int edge[26][26]);
char **readWordsFromFile(const char *filename, int *numWords);
void getFirstLastChar(char *str, char *first, char *last);
void function2(char **words, const int *nword, char notAppear);
void function3(char **words, const int *nword, char notAppear);

#endif //SOFTWARE_ENGINEERING_FUNCTION_H

#include <iostream>
#include <vector>
#include "function.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wwritable-strings"
int N;
using namespace std;


void findPaths(int edge[26][26], int start, int end, vector<int> &path, vector<vector<int>> &allPaths) {
    path.push_back(start);
    if (start == end) {
        vector<int> newpath;
        for (const auto &v: path) {
            newpath.push_back(v);
        }
        allPaths.push_back(newpath);
    } else {
        for (int i = 0; i < 26; ++i) {
            if (edge[start][i] == 1 && start != i) {
                findPaths(edge, i, end, path, allPaths);
            }
        }
    }
    path.pop_back();
}

void find_chain(int edge[26][26], vector<vector<int>> &allChain) {
    int start, end;
    for (start = 0; start < 26; start++) {
        for (end = 0; end < 26; end++) {
            if (end != start) {
                vector<int> path;
                vector<vector<int>> allPaths;
                findPaths(edge, start, end, path, allPaths);
                for (const auto &p: allPaths) {
                    allChain.push_back(p);
                }
            }
        }
    }
}

void print(char **s, int n, vector<vector<string>> &allChain) {
    if (n < 2) {
        return;
    }
    N++;
    vector<string> chain;
    int i;
    for (i = 0; i < n; i++) {
        chain.emplace_back(s[i]);
//        fprintf(fp, "%s ", s[i]);
    }
//    fprintf(fp, "\n");
    allChain.push_back(chain);
}

void print_word(struct wordsList word_list[26][26], int *chain, int depth, int nWord, char **s, int size,
                bool first, vector<vector<string>> &allChain) {
    if (first) {
        print_word(word_list, chain, depth, nWord, s, size, false, allChain);
        if ((word_list[chain[depth]][chain[depth]].headWord)->next != nullptr) {
            s[nWord] = (word_list[chain[depth]][chain[depth]].headWord)->next->s;
            print_word(word_list, chain, depth, nWord + 1, s, size, false, allChain);
        }
    } else {
        if (size <= depth + 1) {
            print(s, nWord, allChain);
            return;
        }
        struct wordPoint *p = (word_list[chain[depth]][chain[depth + 1]].headWord);
        for (; p->next != nullptr; p = p->next) {
            s[nWord] = p->next->s;
            print_word(word_list, chain, depth + 1, nWord + 1, s, size, true, allChain);
        }
    }
}

void
print_word_chain(struct wordsList word_list[26][26], int *chain, int size, vector<vector<string>> &allChain) {
    char *s[10000];
    print_word(word_list, chain, 0, 0, s, size, true, allChain);
}

/**
 * 计算第一个任务。
 * @param notAppear 需求5
 * @param first 要求链开头字母，没有则为'\0'
 * @param last 要求链结束字符，没有则为'\0'
 * @param words 单词数组
 * @param nword 单词个数。
 * @return 无返回值。
 */
void function1(char **words, const int *nword, char notAppear, char first, char last, vector<vector<string>> &chain) {
    N = 0;
//    printf("function1 start\n");
    struct wordsList word_list[26][26];
    int i, j;
    struct wordPoint head[26][26];
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            word_list[i][j].first = i + 'a';
            word_list[i][j].last = j + 'a';
            head[i][j].next = nullptr;
            head[i][j].s = nullptr;
            word_list[i][j].headWord = &(head[i][j]);
        }
    }
    struct wordPoint word[10000];
    for (i = 0; i < *nword; i++) {
        char firstChar, lastChar;
        getFirstLastChar(words[i], &firstChar, &lastChar);
        if (notAppear == '\0' || firstChar != notAppear) {
            struct wordPoint *p = word_list[firstChar - 'a'][lastChar - 'a'].headWord;
            word[i].s = words[i];
            word[i].next = nullptr;
            p->next = &(word[i]);
        }
    }

    int edge[26][26];
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            edge[i][j] = 0;
        }
    }

    for (i = 0; i < *nword; i++) {
        char firstChar, lastChar;
        getFirstLastChar(*(words + i), &firstChar, &lastChar);
        //printf("%s %c %c\n", *(words + i), firstChar, lastChar);
        if (edge[firstChar - 'a'][lastChar - 'a'] == 0) {
            edge[firstChar - 'a'][lastChar - 'a'] = 1;
        }
    }

    vector<vector<int>> allChain;
    find_chain(edge, allChain);
//    fp = fopen("solution.txt", "w");
    for (const auto &p: allChain) {
        int c[26];
        for (i = 0; i < p.size(); i++) {
            c[i] = p[i];
        }
        print_word_chain(word_list, c, (int) p.size(), chain);
    }
//    fclose(fp);
//    printN("solution.txt");
 //   printf("function1 end\n");
}

#pragma clang diagnostic pop
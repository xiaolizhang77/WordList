#include <iostream>
#include <vector>
#include "function.h"
#include <string.h>
#include <fstream>

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

void print(char **s, int n, FILE *fp) {
    if (n < 2) {
        return;
    }
    N++;
    int i;
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s ", s[i]);
    }
    fprintf(fp, "\n");
}

void print_word(struct wordsList word_list[26][26], int *chain, int depth, int nWord, char **s, FILE *fp, int size,
                bool first) {
    if (first) {
        print_word(word_list, chain, depth, nWord, s, fp, size, false);
        if ((word_list[chain[depth]][chain[depth]].headWord)->next != nullptr) {
            s[nWord] = (word_list[chain[depth]][chain[depth]].headWord)->next->s;
            print_word(word_list, chain, depth, nWord + 1, s, fp, size, false);
        }
    } else {
        if (size <= depth + 1) {
            print(s, nWord, fp);
            return;
        }
        struct wordPoint *p = (word_list[chain[depth]][chain[depth + 1]].headWord);
        for (; p->next != nullptr; p = p->next) {
            s[nWord] = p->next->s;
            print_word(word_list, chain, depth + 1, nWord + 1, s, fp, size, true);
        }
    }
}

void print_word_chain(struct wordsList word_list[26][26], int *chain, int size, FILE *fp) {
    char *s[10000];
    print_word(word_list, chain, 0, 0, s, fp, size, true);
}

void printN(char *path) {
    string str = to_string(N) + "\n";

    // 打开文件并读取内容
    ifstream ifs(path);
    string content((istreambuf_iterator<char>(ifs)), (istreambuf_iterator<char>()));
    ifs.close();
    cout << str;

    // 将更改后的内容写回文件
    ofstream ofs(path);
    ofs << str;
    ofs << content;
    ofs.close();
}

/**
 * 计算第一个任务。
 * @param notAppear 需求5
 * @param words 单词数组
 * @param nword 单词个数。
 * @return 无返回值。
 */
void function1(char **words, const int *nword, char notAppear) {
    N = 0;
    printf("function1 start\n");
    struct wordsList word_list[26][26];
    int i, j;
    struct wordPoint head[26][26];
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            word_list[i][j].first = i + 'a';
            word_list[i][j].last = j + 'a';
            head[i][j].next = nullptr;
            head[i][j].s = "this is word head ";
            word_list[i][j].headWord = &(head[i][j]);
        }
    }
    struct wordPoint word[10000];
    for (i = 0; i < *nword; i++) {
        char first, last;
        getFirstLastChar(words[i], &first, &last);
        if (notAppear == '\0' || first != notAppear) {
            struct wordPoint *p = word_list[first - 'a'][last - 'a'].headWord;
            for (; p->next != nullptr; p = p->next) {
                printf(p->s);
            }
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
        char first, last;
        getFirstLastChar(*(words + i), &first, &last);
        //printf("%s %c %c\n", *(words + i), first, last);
        if (edge[first - 'a'][last - 'a'] == 0) {
            edge[first - 'a'][last - 'a'] = 1;
        }
    }

    vector<vector<int>> allChain;
    find_chain(edge, allChain);
    FILE *fp;
    fp = fopen("solution.txt", "w");
    for (const auto &p: allChain) {
        int c[26];
        for (i = 0; i < p.size(); i++) {
            c[i] = p[i];
        }
        print_word_chain(word_list, c, p.size(), fp);
    }
    fclose(fp);
    printN("solution.txt");
    printf("function1 end\n");
}

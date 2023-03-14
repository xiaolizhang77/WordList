//
// Created by leera on 2023/3/13.
//

#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
#include "cstring"

#include "function.h"


//#define struct point point;
//#define struct charPoint charPoint;

std::vector<point *> map2d[26][26];


void get_map(const char *filename, char para_j) {
    int wordNum;
    char **word;

    word = readWordsFromFile(filename, &wordNum);

    if (para_j == 0) {
        for (int i = 0; i < wordNum; i++) {
            point *p = (point *) malloc(sizeof(point));
            p->word = *(word + i);
            p->num = strlen(p->word);
            p->flag = 0;

            std::vector<point *> tmp = map2d[p->word[0] - 'a'][p->word[p->num - 1] - 'a'];
            int j;
            for (j = 0; j < tmp.size(); j++) {
                if (tmp[j]->num < p->num) {
                    break;
                }
            }

            map2d[p->word[0] - 'a'][p->word[p->num - 1] - 'a'].insert(
                    map2d[p->word[0] - 'a'][p->word[p->num - 1] - 'a'].begin() + j, p);
        }

    } else {
        for (int i = 0; i < wordNum; i++) {
            if (*(word + i)[0] != para_j) {
                point *p = (point *) malloc(sizeof(point));
                p->word = *(word + i);
                p->num = strlen(p->word);
                p->flag = 0;

                std::vector<point *> tmp = map2d[p->word[0] - 'a'][p->word[p->num - 1] - 'a'];
                int j;
                for (j = 0; j < tmp.size(); j++) {
                    if (tmp[j]->num < p->num) {
                        break;
                    }
                }

                map2d[p->word[0] - 'a'][p->word[p->num - 1] - 'a'].insert(
                        map2d[p->word[0] - 'a'][p->word[p->num - 1] - 'a'].begin() + j, p);
            }
        }
    }

}

void
dfs(charPoint *root, int i, int j, int k, int flag, int len, int *max_len, charPoint **point, int type, char para_t) {
    charPoint *p = (charPoint *) malloc(sizeof(charPoint));
    p->t = map2d[i][j][k];
    p->t->flag = flag;

    p->prev = root;

    len += type ? p->t->num : 1;

    for (int a = 0; a < 26; a++) {
        for (int b = 0; b < map2d[j][a].size(); b++) {
            if (map2d[j][a][b]->flag != flag) {
                dfs(p, j, a, b, flag, len, max_len, point, type, para_t);
            }
        }
    }

    if (*max_len < len && para_t == p->t->word[p->t->num - 1]) {
        *max_len = len;
        *point = p;
    }
}

void dfs(charPoint *root, int i, int j, int k, int flag, int len, int *max_len, charPoint **point, int type) {
    charPoint *p = (charPoint *) malloc(sizeof(charPoint));
    p->t = map2d[i][j][k];
    p->t->flag = flag;

    p->prev = root;

    len += type ? p->t->num : 1;

    for (int a = 0; a < 26; a++) {
        for (int b = 0; b < map2d[j][a].size(); b++) {
            if (map2d[j][a][b]->flag != flag) {
                dfs(p, j, a, b, flag, len, max_len, point, type);
            }
        }
    }

    if (*max_len < len) {
        *max_len = len;
        *point = p;
    }
}

//有点麻
//参数说明
//filename:文件路径
//para:各个参数
//type:1-c,0-w
//lastpoint:最后一个节点
//max:最大长度或字符数

void search(const char *filename, char para_h, char para_t, char para_j, int type, charPoint **lastPoint, int *max) {
    get_map(filename, para_j);

    charPoint *max_point;
    int max_len = 0;
    int flag = 0;

    if (para_h != 0 && para_t == 0) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < map2d[para_h - 'a'][j].size(); k++) {
                flag++;
                dfs(nullptr, para_h - 'a', j, k, flag, 0, &max_len, &max_point, type);
            }
        }
    } else if (para_h == 0 && para_t != 0) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < map2d[i][j].size(); k++) {
                    flag++;
                    dfs(nullptr, i, j, k, flag, 0, &max_len, &max_point, type, para_t);
                }
            }
        }

    } else if (para_h != 0 && para_t != 0) {
        for (int j = 0; j < 26; j++) {
            for (int k = 0; k < map2d[para_h - 'a'][j].size(); k++) {
                flag++;
                dfs(nullptr, para_h - 'a', j, k, flag, 0, &max_len, &max_point, type, para_t);
            }
        }
    } else {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                for (int k = 0; k < map2d[i][j].size(); k++) {
                    flag++;
                    dfs(nullptr, i, j, k, flag, 0, &max_len, &max_point, type);
                }
            }
        }
    }

    *lastPoint = max_point;
    *max = max_len;

//    charPoint *mmm[100];
//    int i = 0;
//    charPoint *p = max_point;
//    while (p != nullptr) {
//        mmm[i++] = p;
//        p = p->prev;
//    }
//
//    while (i > 0) {
//        std::cout << mmm[--i]->t->word << std::endl;
//    }
//    测试输出


}
#include <cstdlib>

/**
 * 计算给定 26 个节点的有向图中的最长链，并将路径以及链的长度通过指针参数返回。
 *
 * @param edge 一个 26 x 26 的二维数组，表示有向图中节点之间的边。如果 edge[i][j] 的值为 1，则表示从节点 i
 *             到节点 j 有一条有向边；如果 edge[i][j] 的值为 0，则表示从节点 i 到节点 j 没有有向边。
 * @param length 指向一个整数的指针，用于存储最长链的长度。
 * @param nodes 指向一个字符数组的指针，用于存储最长链经过的节点编号(倒序)。
 *
 * @return 无返回值。
 */
void longest_chain(int edge[26][26], int *length, char *nodes) {
    int i, j, k, max_length = 0, max_idx = 0;
    int *lengths = (int *) calloc(26, sizeof(int));
    int *prevs = (int *) calloc(26, sizeof(int));

    // 计算每个节点作为终点的最长链
    for (i = 0; i < 26; i++) {
        lengths[i] = edge[i][i];
        prevs[i] = i;
    }
    for (k = 0; k < 26; k++) {
        for (i = 0; i < 26; i++) {
            for (j = 0; j < 26; j++) {
                if (i != j && edge[j][i] && lengths[j] + 1 + edge[i][i] > lengths[i]) {
                    lengths[i] = lengths[j] + 1 + edge[i][i];
                    prevs[i] = j;
                }
            }
        }
    }

    // 找到最长的链
    for (i = 0; i < 26; i++) {
        //printf("%d : l=%d p=%d\n",i,lengths[i],prevs[i]);
        if (lengths[i] > max_length) {
            max_length = lengths[i];
            max_idx = i;
        }
    }

    // 存储路径和链的长度
    *length = max_length;
    k = 0;
    while (max_idx != prevs[max_idx]) {
        nodes[k] = max_idx + 'a';
        k++;
        max_idx = prevs[max_idx];
    }
    nodes[k] = max_idx + 'a';
    k++;
    nodes[k] = '\0';

    free(lengths);
    free(prevs);
}

void
dfs(int edge[26][26], int finalPath[], int *nFinalPath, int path[], int *nPath, char now, char last, bool self) {
    if (self && edge[now - 'a'][now - 'a'] > 0) {
        path[*nPath] = now - 'a';
        *nPath = *nPath + 1;
        dfs(edge, finalPath, nFinalPath, path, nPath, now, last, false);
        *nPath = *nPath - 1;
    } else {
        if (now == last) {
            if (*nPath > *nFinalPath) {
                *nFinalPath = *nPath;
                int i;
                for (i = 0; i < *nPath; i++) {
                    finalPath[i] = path[i];
                }
            }
            return;
        }
        int i;
        for (i = 0; i < 26; i++) {
            if (i != now - 'a' && edge[now - 'a'][i] > 0) {
                path[*nPath] = i;
                *nPath = *nPath + 1;
                dfs(edge, finalPath, nFinalPath, path, nPath, i + 'a', last, true);
                *nPath = *nPath - 1;
            }
        }
    }
}

#include "stdio.h"

void function2And4(int edge[26][26], char first, char last, int *n, int *answer) {
    int finalPath[100];
    int nFinalPath = 0;
    int path[100];
    path[0] = first - 'a';
    int nPath = 1;
    dfs(edge, finalPath, &nFinalPath, path, &nPath, first, last, true);
    if (nFinalPath > 1) {
//        printf("%c %c %d:", first, last, nFinalPath);
//        int i;
//        for (i = 0; i < nFinalPath; i++) {
//            printf("%c ", finalPath[i] + 'a');
//        }
//        printf("\n");
        *n = nFinalPath;
        int i;
        for (i = 0; i < *n; i++) {
            *(answer + i) = finalPath[i];
        }
        return;
    }
    *n = 0;
}
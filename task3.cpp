#include <cstdlib>
#include <stdio.h>

/**
 * 计算给定 26 个节点的有向图中的最长链，并将路径以及链的长度通过指针参数返回。
 *
 * @param edge 一个 26 x 26 的二维数组，表示有向图中节点之间的边。如果 edge[i][j] 的值大于 0，则表示从节点 i
 *             到节点 j 有一条有向边，权值为 edge[i][j] ；如果 edge[i][j] 的值为 0，则表示从节点 i 到节点 j 没有有向边。
 * @param length 指向一个整数的指针，用于存储最长链的长度。
 * @param nodes 指向一个字符数组的指针，用于存储最长链经过的节点编号（倒叙）。
 *
 * @return 无返回值。
 */
void longest_chain_char(int edge[26][26], int *length, char *nodes) {
    int i, j, k, max_length = 0, max_idx = 0;
    int *lengths = (int *) calloc(26, sizeof(int));
    int *prevs = (int *) calloc(26, sizeof(int));

    // 计算每个节点作为终点的最长链
    for (i = 0; i < 26; i++) {
        //printf("%d \n",edge[i][i]);
        lengths[i] = edge[i][i];
        prevs[i] = i;
    }
    for (k = 0; k < 26; k++) {
        for (i = 0; i < 26; i++) {
            for (j = 0; j < 26; j++) {
                if (i != j && edge[j][i] && lengths[j] + edge[j][i] + edge[i][i] > lengths[i]) {
                    //printf("%d %d %d\n", j, i, lengths[i]);
                    lengths[i] = lengths[j] + edge[j][i] + edge[i][i];
                    prevs[i] = j;
                }
            }
        }
    }

    // 找到最长的链
    for (i = 0; i < 26; i++) {
        printf("%d : l=%d p=%d\n", i, lengths[i], prevs[i]);
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
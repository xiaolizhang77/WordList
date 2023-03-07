#include "function.h"
#include <cstdio>
#include <string.h>

//int main() {
//    int nWord;
//    char notAppear = '\0';
//    char **words = readWordsFromFile("../word_list.txt", &nWord);
//    //function2(words, &nWord, notAppear);
//    function3(words, &nWord, notAppear);
//    return 0;
//}

/**
 * 计算第三个任务。
 * @param notAppear 需求5
 * @param words 单词数组
 * @param nword 单词个数。
 * @return 无返回值。
 */
void function3(char **words, const int *nword, char notAppear) {
    printf("function3 start\n");
    char *(wordMain[26][26]);
    int edge[26][26];
    int i, j;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            wordMain[i][j] = nullptr;
            edge[i][j] = 0;
        }
    }
    for (i = 0; i < *nword; i++) {
        char first, last;
        getFirstLastChar(*(words + i), &first, &last);
        //printf("%s %c %c\n", *(words + i), first, last);
        if (edge[first - 'a'][last - 'a'] < strlen(*(words + i))) {
            edge[first - 'a'][last - 'a'] = strlen(*(words + i));
            wordMain[first - 'a'][last - 'a'] = *(words + i);
        }
    }

    //需求5子功能
    if (notAppear != '\0') {
        for (i = 0; i < 26; i++) {
            //    edge[i][notAppear - 'a'] = 0;
            edge[notAppear - 'a'][i] = 0;
        }
    }

//    for (i = 0; i < 26; i++) {
//        for (j = 0; j < 26; j++) {
//            printf("%d ", edge[i][j]);
//        }
//        printf("\n");
//    }

    char nodes[26];
    int length;
    longest_chain_char(edge, &length, nodes);
//    for(i=0;i<length;i++){
//        printf("%d ",nodes[i]);
//    }
    FILE *fp;
    fp = fopen("solution.txt", "w");
    fprintf(fp, "%d\n", length);
    int nNode;
    for (nNode = 0; nodes[nNode] != '\0'; nNode++);

    for (i = nNode - 1; i > 0; i--) {
        if (edge[nodes[i] - 'a'][nodes[i] - 'a'] > 0) {
            fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
        }
        fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
    }
    if (edge[nodes[i] - 'a'][nodes[i] - 'a'] > 0) {
        fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
    }
    fclose(fp);
    printf("function3 end\n");
}

/**
 * 计算第二个任务。
 * @param notAppear 需求5
 * @param words 单词数组
 * @param nword 单词个数。
 * @return 无返回值。
 */
void function2(char **words, const int *nword, char notAppear) {
    printf("function2 start\n");
    char *(wordMain[26][26]);
    int edge[26][26];
    int i, j;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            wordMain[i][j] = nullptr;
            edge[i][j] = 0;
        }
    }
    for (i = 0; i < *nword; i++) {
        char first, last;
        getFirstLastChar(*(words + i), &first, &last);
        //printf("%s %c %c\n", *(words + i), first, last);
        if (edge[first - 'a'][last - 'a'] == 0) {
            edge[first - 'a'][last - 'a'] = 1;
            wordMain[first - 'a'][last - 'a'] = *(words + i);
        }
    }

    //需求5子功能
    if (notAppear != '\0') {
        for (i = 0; i < 26; i++) {
            //    edge[i][notAppear - 'a'] = 0;
            edge[notAppear - 'a'][i] = 0;
        }
    }

//    for (i = 0; i < 26; i++) {
//        for (j = 0; j < 26; j++) {
//            printf("%d ", edge[i][j]);
//        }
//        printf("\n");
//    }

    char nodes[26];
    int length;
    longest_chain(edge, &length, nodes);
//    for(i=0;i<length;i++){
//        printf("%d ",nodes[i]);
//    }
    FILE *fp;
    fp = fopen("solution.txt", "w");
    fprintf(fp, "%d\n", length);
    int nNode;
    for (nNode = 0; nodes[nNode] != '\0'; nNode++);

    for (i = nNode - 1; i > 0; i--) {
        if (edge[nodes[i] - 'a'][nodes[i] - 'a'] == 1) {
            fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
        }
        fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
    }
    if (edge[nodes[i] - 'a'][nodes[i] - 'a'] == 1) {
        fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
    }
    fclose(fp);
    printf("function2 end\n");
}


#include "function.h"
#include <cstdio>
#include <string.h>

/**
 * 计算第三个任务。
 * @param notAppear 需求5，没有则为'\0'
 * @param words 单词数组
 * @param nword 单词个数。
 * @return 无返回值。
 */
void function3(char **words, const int *nword, char notAppear, char first, char last, vector<string> &result) {
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
    if (first == '\0' && last == '\0') {
        char nodes[26];
        int length;
        longest_chain_char(edge, &length, nodes);
//    for(i=0;i<length;i++){
//        printf("%d ",nodes[i]);
//    }

//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", length);
//        int nNode;
//        for (nNode = 0; nodes[nNode] != '\0'; nNode++);
//
//        for (i = nNode - 1; i > 0; i--) {
//            if (edge[nodes[i] - 'a'][nodes[i] - 'a'] > 0) {
//                fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//                result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//            }
//            fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
//            result.push_back(wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
//        }
//        if (edge[nodes[i] - 'a'][nodes[i] - 'a'] > 0) {
//            fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//            result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//        }
//        fclose(fp);

        int nNode;
        for (nNode = 0; nodes[nNode] != '\0'; nNode++);

        for (i = nNode - 1; i > 0; i--) {
            if (edge[nodes[i] - 'a'][nodes[i] - 'a'] > 0) {
                result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
            }
            result.push_back(wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
        }
        if (edge[nodes[i] - 'a'][nodes[i] - 'a'] > 0) {
            result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
        }
    } else if (first == '\0') {
        printf("only last\n");
        char c = 'a';
        int n;
        int length;
        int maxN = 0;
        int maxLength = 0;
        int *max = nullptr;
        int answer[100];
        for (; c <= 'z'; c++) {
            function3And4(edge, c, last, &n, answer, &length);
            if (length > maxLength) {
                maxN = n;
                max = answer;
                maxLength = length;
            }
        }

//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", maxLength);
//        for (i = 0; i < maxN - 1; i++) {
//            fprintf(fp, "%s\n", wordMain[max[i]][max[i + 1]]);
//            result.push_back(wordMain[max[i]][max[i + 1]]);
//        }
//        fclose(fp);

        for (i = 0; i < maxN - 1; i++) {
            result.push_back(wordMain[max[i]][max[i + 1]]);
        }
    } else if (last == '\0') {
        printf("only first\n");
        char c = 'a';
        int n;
        int length;
        int maxN = 0;
        int maxLength = 0;
        int *max = nullptr;
        int answer[100];
        for (; c <= 'z'; c++) {
            function3And4(edge, first, c, &n, answer, &length);
            if (length > maxLength) {
                maxN = n;
                max = answer;
                maxLength = length;
            }
        }

//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", maxLength);
//        for (i = 0; i < maxN - 1; i++) {
//            fprintf(fp, "%s\n", wordMain[max[i]][max[i + 1]]);
//            result.push_back(wordMain[max[i]][max[i + 1]]);
//        }
//        fclose(fp);

        for (i = 0; i < maxN - 1; i++) {
            result.push_back(wordMain[max[i]][max[i + 1]]);
        }
    } else {
        int maxN = 0;
        int maxLength = 0;
        int max[100];
        function3And4(edge, first, last, &maxN, max, &maxLength);

//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", maxLength);
//        for (i = 0; i < maxN - 1; i++) {
//            fprintf(fp, "%s\n", wordMain[max[i]][max[i + 1]]);
//            result.push_back(wordMain[max[i]][max[i + 1]]);
//        }
//        fclose(fp);

        for (i = 0; i < maxN - 1; i++) {
            result.push_back(wordMain[max[i]][max[i + 1]]);
        }
    }

    printf("function3 end\n");
}

/**
 * 计算第二个任务。
 * @param notAppear 需求5，没有则为'\0'
 * @param words 单词数组
 * @param nword 单词个数。
 * @param first 需求4首字母，没有则为'\0'
 * @param last 需求4尾字母，没有则为'\0'
 * @return 无返回值。
 */
void function2(char **words, const int *nword, char notAppear, char first, char last, vector<string> &result) {
    bool print = false;
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

    if (first == '\0' && last == '\0') {
        char nodes[26];
        int length;
        longest_chain(edge, &length, nodes);
//    for(i=0;i<length;i++){
//        printf("%d ",nodes[i]);
//    }

//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", length);
//        int nNode;
//        for (nNode = 0; nodes[nNode] != '\0'; nNode++);
//        for (i = nNode - 1; i > 0; i--) {
//            if (edge[nodes[i] - 'a'][nodes[i] - 'a'] == 1) {
//                fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//                result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//            }
//            fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
//            result.push_back(wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
//        }
//        if (edge[nodes[i] - 'a'][nodes[i] - 'a'] == 1) {
//            fprintf(fp, "%s\n", wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//            result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
//        }
//        fclose(fp);

        int nNode;
        for (nNode = 0; nodes[nNode] != '\0'; nNode++);
        for (i = nNode - 1; i > 0; i--) {
            if (edge[nodes[i] - 'a'][nodes[i] - 'a'] == 1) {
                result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
            }
            result.push_back(wordMain[nodes[i] - 'a'][nodes[i - 1] - 'a']);
        }
        if (edge[nodes[i] - 'a'][nodes[i] - 'a'] == 1) {
            result.push_back(wordMain[nodes[i] - 'a'][nodes[i] - 'a']);
        }

    } else if (first == '\0') {
        printf("only last\n");
        char c = 'a';
        int n;
        int maxN = 0;
        int *max = nullptr;
        int answer[100];
        for (; c <= 'z'; c++) {
            function2And4(edge, c, last, &n, answer);
            if (n > maxN) {
                maxN = n;
                max = answer;
            }
        }
//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", maxN - 1);
//        for (i = 0; i < maxN - 1; i++) {
//            fprintf(fp, "%s\n", wordMain[max[i]][max[i + 1]]);
//            result.push_back(wordMain[max[i]][max[i + 1]]);
//        }
//        fclose(fp);

        for (i = 0; i < maxN - 1; i++) {
            result.push_back(wordMain[max[i]][max[i + 1]]);
        }
    } else if (last == '\0') {
        printf("only first\n");
        char c = 'a';
        int n;
        int maxN = 0;
        int *max = nullptr;
        int answer[100];
        for (; c <= 'z'; c++) {
            function2And4(edge, first, c, &n, answer);
            if (n > maxN) {
                maxN = n;
                max = answer;
            }
        }
//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", maxN - 1);
//        for (i = 0; i < maxN - 1; i++) {
//            fprintf(fp, "%s\n", wordMain[max[i]][max[i + 1]]);
//            result.push_back(wordMain[max[i]][max[i + 1]]);
//        }
//        fclose(fp);

        for (i = 0; i < maxN - 1; i++) {
            result.push_back(wordMain[max[i]][max[i + 1]]);
        }
    } else {
        int maxN = 0;
        int max[100];
        function2And4(edge, first, last, &maxN, max);
//        FILE *fp;
//        fp = fopen("solution.txt", "w");
//        fprintf(fp, "%d\n", maxN - 1);
//        for (i = 0; i < maxN - 1; i++) {
//            fprintf(fp, "%s\n", wordMain[max[i]][max[i + 1]]);
//            result.push_back(wordMain[max[i]][max[i + 1]]);
//        }
//        fclose(fp);

        for (i = 0; i < maxN - 1; i++) {
            result.push_back(wordMain[max[i]][max[i + 1]]);
        }
    }
    printf("function2 end\n");
}


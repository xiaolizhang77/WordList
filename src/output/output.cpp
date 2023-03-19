//
// Created by leera on 2023/3/16.
//

#include "output.h"

int output(int size, vector<vector<string>> &result) {
    FILE *fp;
    fp = fopen("solution.txt", "w");
    fprintf(fp, "%d\n", size);
    for (int i = 0; i < size; i++) {
        for (auto & j : result[i]) {
            fprintf(fp, "%s ", j.c_str());
//            printf("%s ", result[i][j].c_str());
        }
        fprintf(fp, "\n");
//        printf(" \n");
    }
    fclose(fp);
    return 1;
}

int output(int size, vector<string> &result) {
    FILE *fp;
    fp = fopen("solution.txt", "w");
    fprintf(fp, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(fp, "%s\n", result[i].c_str());
    }
    fclose(fp);
    return 1;
}
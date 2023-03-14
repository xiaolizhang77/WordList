#include <cstdio>
#include <cstdlib>
#include <cctype>

/**
 * 该函数用于从指定文件中读取所有的单词，并将它们存储在一个动态分配的char**数组中。
 * 函数最多读取10000个单词，每个单词最长为50个字符。
 * @param filename 文件名
 * @param numWords 一个指向整数的指针，用于存储读取的单词数量。
 * @return 一个char**指针，指向存储所有单词的动态分配的数组。如果文件无法打开或内存分配失败，则返回NULL。
 * 调用函数后，使用完该数组后，需要手动释放内存以防止内存泄漏。
 */
char **readWordsFromFile(const char *filename, int *numWords) {
    printf("readWordsFromFile start\n");
    FILE *fp;
    char **words;
    char c;

    fp = fopen(filename, "r");

    if (fp == nullptr) {
        printf("Failed to open file\n");
        return nullptr;
    }

    int count = 0;
    int wordIndex = 0;
    int wordLength = 0;
    bool inWord = false;

    // Allocate memory for the words array
    words = (char **) malloc(10000 * sizeof(char *));

    if (words == nullptr) {
        printf("Memory allocation failed\n");
        return nullptr;
    }

    // Read each word from the file
    while ((c = fgetc(fp)) != EOF && count < 10000) {
        if (isalpha(c)) {
            if (!inWord) {
                inWord = true;
                wordLength = 0;
                words[wordIndex] = (char *) malloc(50 * sizeof(char));
            }
            if (c >= 'A' && c <= 'Z') {
                words[wordIndex][wordLength] = c - 'A' + 'a';
            } else {
                words[wordIndex][wordLength] = c;
            }
            wordLength++;
        } else {
            if (inWord) {
                inWord = false;
                words[wordIndex][wordLength] = '\0';
                wordIndex++;
            }
        }
        count++;
    }
    if (wordLength != 0) {
        words[wordIndex][wordLength] = '\0';
        *numWords = ++wordIndex;
    }
    fclose(fp);
    printf("readWordsFromFile end\n");
    return words;
}
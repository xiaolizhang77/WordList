void getFirstLastChar(char *str, char *first, char *last) {
    *first = *str;
    char* p = str;
    while (*p != '\0') {           // 遍历字符串，直到遇到 null 字符为止
        p++;                      // 将指针向后移动一个位置
    }
    p--;
    *last = *p;
}
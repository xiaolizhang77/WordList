#include "string"

void getFirstLastChar(char *str, char *first, char *last) {
    *first = *str;
    char* p = str;
    while (*p != '\0') {           // 遍历字符串，直到遇到 null 字符为止
        p++;                      // 将指针向后移动一个位置
    }
    p--;
    *last = *p;
}

int checkFileFormat(std::string &fn) {
    for (int i = 0; i < fn.length(); i++) {
        if (fn[i] == '.') {
            if (fn.length() - i == 4) {
                if (fn[i + 1] == 't' && fn[i + 2] == 'x' && fn[i + 3] == 't') {
                    return 1;
                } else { return 0; }
            } else {
                return 0;
            }
        }
    }
    return 0;
}
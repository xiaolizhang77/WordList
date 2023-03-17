#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "word_list.h" // 如果你有一个头文件定义了libword_list.dll中的接口，请在此处包含

int main() {
    std::cout << "test start..." << std::endl;

    // 从文件中读取字符串
    char **strings;
    int n;
    strings = readWordsFromFile("test.txt", &n);

    vector<vector<string>> result;
    gen_chains_all(strings, n, result);

    // 测试完成
    std::cout << "test end！" << std::endl;

    return 0;
}

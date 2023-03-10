#include <iostream>
#include "getopt.h"
#include "string"
//#include <sys/types.h>
#include <sys/stat.h>
//#include <unistd.h>
#include "function.h"
int main() {
    int nWord;
    char **words = readWordsFromFile("../word_list.txt", &nWord);
    function1(words,&nWord,'\0');
    return 0;
}
//
//int checkFileFormat(std::string &fn) {
//    for (int i = 0; i < fn.length(); i++) {
//        if (fn[i] == '.') {
//            if (fn.length() - i == 4) {
//                if (fn[i + 1] == 't' && fn[i + 2] == 'x' && fn[i + 3] == 't') {
//                    return 1;
//                } else { return 0; }
//            } else {
//                return 0;
//            }
//        }
//    }
//    return 0;
//}
//
//int main(int argc, char *argv[]) {
//    int o;
//
//    int para_n = 0, para_w = 0, para_c = 0, para_h = 0, para_t = 0, para_j = 0, para_r = 0;
//    int para_non = 0;
//    std::string f_road;
//    std::string para_h_arg, para_t_arg, para_j_arg;
//
//
//    while ((o = getopt(argc, argv, "n:w:c:h:t:j:r")) != -1) {
//
//        switch (o) {
//            case 'n':
//                para_n++;
//                f_road = optarg;
//                break;
//            case 'w':
//                para_w++;
//                f_road = optarg;
//                break;
//            case 'c':
//                para_c++;
//                f_road = optarg;
//                break;
//            case 'h':
//                para_h++;
//                para_h_arg = optarg;
//                break;
//            case 't':
//                para_t++;
//                para_t_arg = optarg;
//                break;
//            case 'j':
//                para_j++;
//                para_j_arg = optarg;
//                break;
//            case 'r':
//                para_r++;
//                break;
//            case '?':
//                para_non++;
//                break;
//            default:
//                break;
//
//        }
//    }
//
//
//    if (para_non != 0) {
//        std::cout << "1 存在无效参数" << std::endl;
//    }
//
//    if (para_n + para_w + para_c + para_h + para_t + para_r + para_j == 0) {
//        std::cout << "2 参数不存在" << std::endl;
//    }
//
//    if ((para_n + para_w + para_c == 0) && (para_h + para_t + para_r + para_j >= 1)) {
//        std::cout << "3 附加参数不能独自存在" << std::endl;
//    }
//
//    if (para_n + para_w + para_c > 1) {
//        std::cout << "4 参数不兼容" << std::endl;
//    }
//
//    if (((para_h | para_t) | (para_r | para_j)) > 1) {
//        std::cout << "5 参数重复" << std::endl;
//    }
//
//    if (!checkFileFormat(f_road)) {
//        std::cout << "6 文件格式错误" << std::endl;
//    }
//
//    struct stat *buf = nullptr;
//    if (stat(f_road.c_str(), buf) != 0) {
//        std::cout << "7 文件不存在" << std::endl;
//    }
//
//    if ((para_h != 0 && para_h_arg.length() != 1) || (para_t != 0 && para_t_arg.length() != 1) ||
//        (para_j != 0 && para_j_arg.length() != 0)) {
//        std::cout << "8 参数存在问题" << std::endl;
//    }
//
//    int nWord;
//    char **words = readWordsFromFile("../word_list.txt", &nWord);
//    // n
//    // TODO
//
//
//    if (para_w) {// w
//        if (para_j == 0) {
//            function2(words, &nWord, '\0');
//        } else {
//            function2(words, &nWord, para_j_arg[0]);
//        }
//    } else if (para_c) {// c
//        if (para_j == 0) {
//            function3(words, &nWord, '\0');
//        } else {
//            function3(words, &nWord, para_j_arg[0]);
//        }
//    }
//    return 0;
//}


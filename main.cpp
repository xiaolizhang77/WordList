#include <iostream>
#include "getopt.h"
#include "string"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "function.h"

#include "exceptions.h"

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

int main(int argc, char *argv[]) {
    int o;

    int para_n = 0, para_w = 0, para_c = 0, para_h = 0, para_t = 0, para_j = 0, para_r = 0;
    int para_non = 0;
    std::string f_road;
    std::string para_h_arg, para_t_arg, para_j_arg;


    while ((o = getopt(argc, argv, "n:w:c:h:t:j:r")) != -1) {

        switch (o) {
            case 'n':
                para_n++;
                f_road = optarg;
                break;
            case 'w':
                para_w++;
                f_road = optarg;
                break;
            case 'c':
                para_c++;
                f_road = optarg;
                break;
            case 'h':
                para_h++;
                para_h_arg = optarg;
                break;
            case 't':
                para_t++;
                para_t_arg = optarg;
                break;
            case 'j':
                para_j++;
                para_j_arg = optarg;
                break;
            case 'r':
                para_r++;
                break;
            case '?':
                para_non++;
                break;
            default:
                break;

        }
    }

    try {
        if (para_n + para_w + para_c + para_h + para_t + para_r + para_j == 0) {
            throw none_parameter();
        }

        if (para_non != 0) {
            throw unknown_parameter();
        }

        if (para_n + para_w + para_c == 0) {
            throw single_additional_parameter();
        }

        if (para_n + para_w + para_c > 1) {
            throw incompatible_parameter();
        }

        if (((para_h | para_t) | (para_r | para_j)) > 1) {
            throw repeat_parameter();
        }

        if (!checkFileFormat(f_road)) {
            throw format_filename();
        }

        struct stat buf{};
        if (stat(f_road.c_str(), &buf) != 0) {
            throw none_exist_file();
        }

        if ((para_h != 0 && para_h_arg.length() != 1) || (para_t != 0 && para_t_arg.length() != 1) ||
            (para_j != 0 && para_j_arg.length() != 0)) {
            throw format_parameter_content();
        }
    } catch (none_parameter &e) {
        std::cout << e.what() << std::endl;
        exit(-1);
    }
    catch (unknown_parameter &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
    catch (single_additional_parameter &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
    catch (incompatible_parameter &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
    catch (repeat_parameter &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }
    catch (format_filename &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    } catch (none_exist_file &e) {
        std::cerr << f_road << std::endl;
        std::cerr << e.what() << std::endl;
        exit(-1);
    } catch (format_parameter_content &e) {
        std::cerr << e.what() << std::endl;
        exit(-1);
    }


    int nWord;
    char **words = readWordsFromFile(f_road.c_str(), &nWord);
    // n
    // TODO


    if (para_w) {// w
        if (para_j == 0) {
            function2(words, &nWord, '\0');
        } else {
            function2(words, &nWord, para_j_arg[0]);
        }
    } else if (para_c) {// c
        if (para_j == 0) {
            function3(words, &nWord, '\0');
        } else {
            function3(words, &nWord, para_j_arg[0]);
        }
    }
    return 0;
}

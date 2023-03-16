#include <iostream>
#include "getopt.h"
#include "string"
#include <sys/stat.h>
#include <unistd.h>

#include "function/function.h"
#include "exceptions/exceptions.h"
#include "api/api.h"
#include "output/output.h"

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

    if (para_n != 0) {
        vector<vector<string>> result;
        int size;
        size = gen_chains_all(words, nWord, result);
        output(size,result);
    } else if (para_w != 0) {
        vector<string> result;
        int size;
        bool en_loop = para_r != 0;
        size = gen_chain_word(words, nWord, result, para_h_arg[0], para_t_arg[0], para_j_arg[0],
                              en_loop);
        output(size,result);

    }else if(para_c!=0){
        vector<string> result;
        int size;
        bool en_loop = para_r != 0;
        size = gen_chain_char(words, nWord, result, para_h_arg[0], para_t_arg[0], para_j_arg[0],
                              en_loop);
        output(size,result);
    }

    return 0;
}

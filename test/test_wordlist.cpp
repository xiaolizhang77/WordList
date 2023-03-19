#include <iostream>
#include <vector>
#include <string>
#include "word_list.h"

int main() {
    std::cout << "test start..." << std::endl;

    // 从文件中读取字符串
    char *strings[100] = {
            "uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuv",
            "uuuuv",
            "uuv",
            "vw",
            "wx",
            "xy",
            "yz",
            "yy",
            "aaaaab",
            "aab",
            "bbbbbbc",
            "cccg",
            "cccd",
            "dg",
            "yz",
            "yy",
            "aaaaab",
            "aab",
            "bbbbbbc",
            "cccg",
            "cccd",
            "dg",
            "yz",
            "yy",
            "aaaaab",
            "aab",
            "bbbbbbc",
            "cccg",
            "cccd",
            "dg",
            "gggggj",
            "hi",
            "ij",
            "jm",
            "mn",
            "opq",
            "opq",
            "opq",
            "opq",
            "opq",
            "op",
            "oo",
            "bb"
    };

    int n = 43;

    vector<vector<string>> result;
    gen_chains_all(strings, n, result);

    vector<string> result2;
    gen_chain_char(strings, n, result2, '\0', 'c', 'b', false);
    gen_chain_char(strings, n, result2, 'a', 'c', 'b', false);
    gen_chain_char(strings, n, result2, 'a', '\0', 'b', false);
    gen_chain_char(strings, n, result2, 'a', 'c', '\0', false);
    gen_chain_char(strings, n, result2, '\0', '\0', '\0', false);
    gen_chain_char(strings, n, result2, 'a', '\0', '\0', false);
    gen_chain_char(strings, n, result2, '\0', 'c', '\0', false);
    gen_chain_char(strings, n, result2, '\0', '\0', 'a', false);
    gen_chain_char(strings, n, result2, '\0', 'c', 'b', true);
    gen_chain_char(strings, n, result2, 'a', 'c', 'b', true);
    gen_chain_char(strings, n, result2, 'a', '\0', 'b', true);
    gen_chain_char(strings, n, result2, 'a', 'c', '\0', true);
    gen_chain_char(strings, n, result2, '\0', '\0', '\0', true);
    gen_chain_char(strings, n, result2, 'a', '\0', '\0', true);
    gen_chain_char(strings, n, result2, '\0', 'c', '\0', true);
    gen_chain_char(strings, n, result2, '\0', '\0', 'a', true);

    gen_chain_word(strings, n, result2, '\0', 'c', 'b', false);
    gen_chain_word(strings, n, result2, 'a', 'c', 'b', false);
    gen_chain_word(strings, n, result2, 'a', '\0', 'b', false);
    gen_chain_word(strings, n, result2, 'a', 'c', '\0', false);
    gen_chain_word(strings, n, result2, '\0', '\0', '\0', false);
    gen_chain_word(strings, n, result2, 'a', '\0', '\0', false);
    gen_chain_word(strings, n, result2, '\0', 'c', '\0', false);
    gen_chain_word(strings, n, result2, '\0', '\0', 'a', false);
    gen_chain_word(strings, n, result2, '\0', 'c', 'b', true);
    gen_chain_word(strings, n, result2, 'a', 'c', 'b', true);
    gen_chain_word(strings, n, result2, 'a', '\0', 'b', true);
    gen_chain_word(strings, n, result2, 'a', 'c', '\0', true);
    gen_chain_word(strings, n, result2, '\0', '\0', '\0', true);
    gen_chain_word(strings, n, result2, 'a', '\0', '\0', true);
    gen_chain_word(strings, n, result2, '\0', 'c', '\0', true);
    gen_chain_word(strings, n, result2, '\0', '\0', 'a', true);


    // 从文件中读取字符串
    char *strings2[100] = {
            "uuuuv",
            "vw",
            "wx",
            "xy",
            "yz",
            "yy",
            "aaaaab",
            "aab",
            "bbbbbbc",
            "cccg",
            "cccd",
            "dg",
            "gggggj",
            "hi",
            "ij",
            "jm",
            "mn",
            "opq",
            "op",
            "oo",
            "bb",
            "za",
            "ga",
            "gb",
            "sb",
            "lj",
            "ssl",
            "somethings"
    };

    n = 28;
    gen_chain_word(strings2, n, result2, '\0', 'c', 'b', true);
    gen_chain_word(strings2, n, result2, 'a', 'c', 'b', true);
    gen_chain_word(strings2, n, result2, 'a', '\0', 'b', true);
    gen_chain_word(strings2, n, result2, 'a', 'c', '\0', true);
    gen_chain_word(strings2, n, result2, '\0', '\0', '\0', true);
    gen_chain_word(strings2, n, result2, 'a', '\0', '\0', true);
    gen_chain_word(strings2, n, result2, '\0', 'c', '\0', true);
    gen_chain_word(strings2, n, result2, '\0', '\0', 'a', true);
    gen_chain_char(strings2, n, result2, '\0', 'c', 'b', true);
    gen_chain_char(strings2, n, result2, 'a', 'c', 'b', true);
    gen_chain_char(strings2, n, result2, 'a', '\0', 'b', true);
    gen_chain_char(strings2, n, result2, 'a', 'c', '\0', true);
    gen_chain_char(strings2, n, result2, '\0', '\0', '\0', true);
    gen_chain_char(strings2, n, result2, 'a', '\0', '\0', true);
    gen_chain_char(strings2, n, result2, '\0', 'a', '\0', true);
    gen_chain_char(strings2, n, result2, '\0', '\0', 'a', true);

    char *strings3[100] = {
            "mampikdfgfdazsi", "nyqaffouyi", "ftcmodfvab", "ysadyjbqjn", "ytofdatiic", "ucbbpgldjt", "rpvcjfifda",
            "yzaspfqqhl", "rjzbyezhri", "tcbvwvlcsdfdfdfsdfsdfghjksdfghjklsdfghjklmk", "rmobyrfzad", "cgbuxirxka", "qzkfztenzl", "xnmwvbptte",
            "kwnjsdfsrpwmi", "kchpcaamde", "vvwrkckcyg", "xywwslplun", "xnghndhace", "seeqprvqao", "wtbrjfujid",
            "zftjdfdzcbwva", "xjsbrklhod", "lgmpnndykj", "oselbndknc", "pjsxolpfwi", "karyajsnmi", "tyxrtjsfgr",
            "womlfmmbtu", "qtqajuhmqa", "zmdojgvkbc", "lddwlzpisb", "zwvdqcdjqw", "xbppktxwaw", "wlhjmusfzk",
            "wgktdyjmjg", "jbwmsdfejcjkb", "udksdfoollyxk", "rfipdfuqfj", "ztwqjdqzgm", "udmjcehedc", "tysjpkyczo",
            "vdbntdfrba", "spbcnyibpd", "xqldhshojo", "ketesrwljj", "sjazrwsuah", "qzxaqeqwxp", "kscdthxkpb",
            "ztmsdfprhtmks", "ynvqpuggfd", "ryynaozysl", "miwhzzvxof", "nblgqayowf", "thqsrqhcqa", "eiiucfhbyd",
            "uovoiyglec", "iuufqbjsdfpzg", "sgpagbnvmk", "qvhumtzvqg", "ydsvqlhmrm", "lgfopmnkma", "qvdemjdlkn",
            "ecrcrbtfia", "zfvdfgyhahth", "nisdfswonbcbf", "pqzygcqhif", "zhkppannvn", "ollnjzjssj", "jpgkdxrtcc",
            "zezjjmfrsdzi", "zskilnqcfi", "niimmanhei", "wucmghusku", "odsoyfdrwa", "pobfgkkmti", "zmnvvgfnvo",
            "mewwesdfylnjg", "yanypvwemb", "ytgysdfypxpcn", "rkquecuruj", "kxigidiwuj", "wquaychqea", "tlclyiknac",
            "yxefklbnys", "ffwiyfrgpb", "xfnvbqpsdftjutcr", "ttwfzntpzl", "nxvszgwlbj", "zonaraujbc", "tihbhnfrbb",
            "tnjaegslsc", "ruskfsdfubaaq"
    };

    n = 93;
    gen_chains_all(strings3, n, result);

    char *strings4[100] = {
            "mampikazsi"
    };

    n = 1;
    gen_chains_all(strings4, n, result);

// 测试完成
    std::cout << "test end!" <<
              std::endl;

    return 0;
}

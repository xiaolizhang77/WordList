//
// Created by leera on 2023/3/7.
//

#ifndef WORDLIST_EXCEPTION_H
#define WORDLIST_EXCEPTION_H

#include "iostream"
#include "exception"


class unknown_parameter : public std::exception {
public:
    const char *what();
};

class none_parameter : public std::exception {
public:
    const char *what();
};

class incompatible_parameter : public std::exception {
public:
    const char *what();
};

class single_additional_parameter : public std::exception {
public:
    const char *what();
};

class repeat_parameter : public std::exception {
public:
    const char *what();
};

class format_filename : public std::exception {
public:
    const char *what();
};

class none_exist_file : public std::exception {
public:
    const char *what();
};

class format_parameter_content : public std::exception {
public:
    const char *what();
};

#endif //WORDLIST_EXCEPTION_H

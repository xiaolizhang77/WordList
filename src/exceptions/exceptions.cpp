//
// Created by leera on 2023/3/7.
//

#include "exceptions.h"

const char *unknown_parameter::what() {
    return "There are unknown parameters.";
}

const char *none_parameter::what() {
    return "There are no parameters.";
}

const char *incompatible_parameter::what() {
    return "The parameters are not compatible.";
}

const char *single_additional_parameter::what() {
    return "Additional parameters cannot exist alone.";
}

const char *repeat_parameter::what() {
    return "Duplicate parameters.";
}

const char *format_filename::what() {
    return "The filename format is incorrect.";
}

const char *none_exist_file::what() {
    return "The file does not exist.";
}

const char *format_parameter_content::what() {
    return "Additional parameter content can only be one letter.";
}





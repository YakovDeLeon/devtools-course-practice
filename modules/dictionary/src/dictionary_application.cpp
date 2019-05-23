// Copyright 2019 Yakovlev Denis

#include "include/dictionary_application.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>

std::string DicitonaryApplication::operator()(int argc, const char ** argv) {
    if (ValidateArguments(argc, argv)) {
        Word word;
        switch (xmap[op_]) {
        case etOperation::eSEARCH_ELEMENT:
            word = dict_.Find(searchElem_);
            return std::string(word.first + " " + std::to_string(word.second));
            break;
        case etOperation::eSEARCH_MAX_ELEMENT:
            word = dict_.FindMax();
            return std::string(word.first + " " + std::to_string(word.second));
            break;
        case etOperation::eSEARCH_MIN_ELEMENT:
            word = dict_.FindMin();
            return std::string(word.first + " " + std::to_string(word.second));
            break;
        }
    }
    return message_;
}

void DicitonaryApplication::Help(
    const char * appname,
    const std::string& message) {
    message_ = std::string(message) +
        "\n\nThis is a dictionary application.\n"
        "Please provide arguments in the following format:\n\n"
        "  $ " + appname + " <word_1_key> <word_1_value> "
        "<word_2_key> <word_2_value> ... " +
        " <word_k_key> <word_k_value> <operation> "
        "<word_key>\n\n"
        "Where word_key is string and word_value is integer number, " +
        "and <operation> is one of\n"
        "-s' - search element,\n"
        "-smin' - search min element,\n"
        "-smax' - search max elemet,\n";
}

bool DicitonaryApplication::ValidateNumberOfArguments(
    int argc,
    const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc < 4) {
        Help(argv[0], "ERROR: Should be at least 3 arguments.\n\n");
        return false;
    }
    return true;
}

bool DicitonaryApplication::ValidateArguments(
    int argc,
    const char ** argv) {
    if (!ValidateNumberOfArguments(argc, argv)) {
        return false;
    }
    const char* itOp = nullptr;
    int indexOperation = 0;
    for (; indexOperation != argc; indexOperation++) {
        if (strcmp(argv[indexOperation], "-s") == 0
        || strcmp(argv[indexOperation], "-smin") == 0
        || strcmp(argv[indexOperation], "-smax") == 0) {
            itOp = argv[indexOperation];
            break;
        }
    }
    if (itOp) {
        int i = 1;
        while (i < indexOperation) {
            try {
                dict_.Insert(Word(argv[i], std::stoi(argv[i + 1])));
            }
            catch (std::exception &e) {
                Help(argv[0], "Invalid key!" + std::string(e.what()));
                return false;
            }
            i += 2;
        }
        if (i == indexOperation) {
            op_ = itOp;
            if (xmap[op_] == etOperation::eSEARCH_ELEMENT) {
                if (i + 1 != argc) {
                        searchElem_ = argv[i + 1];
                        return true;
                } else {
                    Help(argv[0], "Invalid search element!");
                    return false;
                }
            }
            return true;
        }
    }
    Help(argv[0], "Invalid operation!");
    return false;
}

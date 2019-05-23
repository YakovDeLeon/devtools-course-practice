// Copyright 2019 Obolenskiy Arseniy
#include <cstring>
#include <limits>
#include <iostream>
#include <stdexcept>
#include <string>
#include "include/tree_application.h"

std::string TreeApplication::Help(const char *appname) {
    return "This is application for tree class\n"
           "Usage:\n"
           "> " + std::string(appname) + " actions that described below\n"
           "Actions:\n"
           "add <value> - add value to the tree\n"
           "del <value> - delete value from the tree\n"
           "search <value> - find the value in the tree\n"
           "clear - delete the whole tree\n";
}

std::string TreeApplication::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return Help(*argv);
    }
    try {
        for (int i = 1; i < argc; ) {
            int offset = ParseOperation(argv + i);
            i += offset;
        }
        return out_.str();
    } catch (std::runtime_error &re) {
        return re.what();
    }
}

int TreeApplication::ParseNumber(const char *s) {
    int len = strlen(s);
    if ((s[0] != '-' && !isdigit(s[0])) || (s[0] == '-' && len == 1))
        throw std::runtime_error(std::string(s) + " is not the number");
    for (int i = 1; i < len; ++i)
        if (!isdigit(s[i]))
            throw std::runtime_error(std::string(s) + " is not the number");
    int64_t result = std::strtol(s, nullptr, 10);
    if (result <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
        result >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
        throw std::runtime_error("Number is out of bounds");
    }
    return static_cast<int>(result);
}

int TreeApplication::ParseOperation(const char **argv) {
    if (std::strcmp(*argv, "add") == 0) {
        int value = ParseNumber(*(argv + 1));
        t_.Add(value);
        return 2;
    }
    if (std::strcmp(*argv, "del") == 0) {
        int value = ParseNumber(*(argv + 1));
        t_.Del(value);
        return 2;
    }
    if (std::strcmp(*argv, "search") == 0) {
        int value = ParseNumber(*(argv + 1));
        int verdict = t_.Search(value);
        if (verdict)
            out_ << "(" << value << " is found, count: " << verdict << ") ";
        else
            out_ << "(" << value << " is not found) ";
        return 2;
    }
    if (std::strcmp(*argv, "clear") == 0) {
        t_.Clear();
        return 1;
    }
    throw std::runtime_error(std::string("Unknown operation: ") +
                             std::string(*argv));
    return 0;
}

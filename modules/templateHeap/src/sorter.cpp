// Copyright 2019 Timakin Nikita

#include "include/sorter.h"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include "include/heap.h"

std::string Sorter::HelpMessage(const char* appname) {
    return std::string("") + "This is an application which allows you " +
           "to sort numbers in reverse order\n" +
           "Please provide arguments in the following format:\n" +
           "  $ " + appname + " num_1 num_2 ... num_n\n";
}

bool Sorter::CheckArguments(int argc, const char** argv) {
    auto no_argumnets = [&argc] { return argc == 1; };
    auto first_arg_is_help = [&argv] { return std::string(argv[1]) == "help";};

    if (no_argumnets() || first_arg_is_help()) {
        std::cout << HelpMessage(argv[0]);
        return false;
    }

    try {
        for (int i = 1; i < argc; ++i)
            args_.emplace_back(std::stof(argv[i]));
    }
    catch (std::exception&) {
        std::cout << "Input error\n\n" + HelpMessage(argv[0]);
        return false;
    }

    return true;
}

std::string Sorter::operator()(int argc, const char** argv) {
    if (!CheckArguments(argc, argv))
        return "";

    Heap<float> heap;
    std::ostringstream result;

    for (auto value : heap.HeapSort(args_))
        result << value << " ";
    result << "\n";

    return result.str();
}

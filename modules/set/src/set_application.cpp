// Copyright 2019 Alexander Batashev

#include "include/set_application.h"

#include <algorithm>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

void SetApplication::Help(const char *appname, const char *message) {
    message_ = std::string(message) +
            "This is a set application.\n"
            "Please provide arguments in the following format:\n"

            "  $ " + appname + " <n1> <n2> ... <nk> "
            "<operation>" + " <m1> <m2> ... <ml>\n"

            "Where all arguments are integer numbers, "
            "and <operation> is one of\n"
            "'u' - union,\n"
            "'i' - intersection,\n"
            "'d' - difference,\n"
            "'sd' - symmetric difference.\n";
}

bool SetApplication::ValidateArguments(int argc, const char **argv) {
    bool no_arguments = argc == 1;
    bool first_argument_is_help =
            std::string(argv[1] != nullptr ? argv[1] : "") == "help";
    if (no_arguments || first_argument_is_help) {
        Help(argv[0]);
        return false;
    }

    try {
        std::vector<std::string> arguments_ = std::vector<std::string>();
        for (int i = 1; i < argc; i++) {
            arguments_.emplace_back(argv[i]);
        }

        auto it_op = std::find_if(arguments_.begin(), arguments_.end(),
                [](const std::string &str) -> bool {
                    return str == "u" ||str == "i" ||
                    str == "d" || str == "sd";
                });

        if (it_op != arguments_.end()) {
            ChooseOperation(*it_op);
            std::transform(arguments_.begin(), it_op,
                           std::back_inserter(elems1_),
                           [](std::string &str) {
                               return std::stoi(str);
                           });
            std::transform(std::next(it_op), arguments_.end(),
                           std::back_inserter(elems2_),
                           [](std::string &str) {
                               return std::stoi(str);
                           });
        } else {
            Help(argv[0], "Missed operation!\n");
            return false;
        }
    }
    catch (std::exception &e) {
        Help(argv[0], "Input error!\n");
        return false;
    }

    return true;
}

void SetApplication::ChooseOperation(const std::string &str) {
    if (str == "u") {
        op_ = Operation::Union;
    } else if (str == "i") {
        op_ = Operation::Intersection;
    } else if (str == "d") {
        op_ = Operation::Difference;
    } else if (str == "sd") {
        op_ = Operation::SymmetricDifference;
    }
}

std::string SetApplication::operator()(int argc, const char **argv) {
    if (!ValidateArguments(argc, argv)) {
        return message_;
    }

    Set<int> set1(elems1_);
    Set<int> set2(elems2_);
    Set<int> res;

    std::ostringstream stream;

    if (op_ == Operation::Union) {
        res = Set<int>::Union(set1, set2);
    } else if (op_ == Operation::Intersection) {
        res = Set<int>::Intersection(set1, set2);
    } else if (op_ == Operation::Difference) {
        res = Set<int>::Difference(set1, set2);
    } else if (op_ == Operation::SymmetricDifference) {
        res = Set<int>::SymmetricDifference(set1, set2);
    }

    for (const auto &item : res) {
        stream << item << " ";
    }
    stream << "\n";

    return stream.str();
}

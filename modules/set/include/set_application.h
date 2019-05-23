// Copyright 2019 Trykin Alexander

#ifndef MODULES_SET_INCLUDE_SET_APPLICATION_H_
#define MODULES_SET_INCLUDE_SET_APPLICATION_H_

#include "include/set.h"

#include <string>
#include <vector>

class SetApplication {
 private:
    std::vector<int> elems1_;
    std::vector<int> elems2_;
    enum class Operation {
        Union,
        Intersection,
        Difference,
        SymmetricDifference
    } op_;
    std::string message_;

    void Help(const char *appname, const char *message = "");
    bool ValidateArguments(int argc, const char **argv);
    void ChooseOperation(const std::string &str);

 public:
    SetApplication() = default;
    std::string operator()(int argc, const char **argv);
};

#endif  // MODULES_SET_INCLUDE_SET_APPLICATION_H_

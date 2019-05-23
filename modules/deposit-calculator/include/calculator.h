// Copyright 2019 Vorobev Pavel

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_CALCULATOR_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_CALCULATOR_H_

#include <string>

class Calculator {
 public:
    Calculator() = default;
    Calculator(const Calculator&) = default;

    std::string operator() (int argc, const char** argv);

 private:
     std::string Help(const char* appname, const char* message = "");
     bool ValidateArgs(int argc, const char** argv);
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_CALCULATOR_H_

// Copyright 2019 Prytov Denis

#ifndef MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CALCULATOR_H_
#define MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CALCULATOR_H_

#include <string>

class CurrencyCalculator {
 public:
    CurrencyCalculator() = default;
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArgs(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double value;
        std::string operation;
    } Arguments;
};

#endif  // MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CALCULATOR_H_

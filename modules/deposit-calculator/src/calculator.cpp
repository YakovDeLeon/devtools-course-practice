// Copyright 2019 Vorobev Pavel

#include "include/calculator.h"
#include <string>
#include <iostream>
#include "include/deposit_calculator.h"

std::string Calculator::Help(const char* appname, const char* message) {
    return std::string(message) +
        "This application allows you to calculate " +
        "amount of your deposit with provided initial " +
        "amount of money, interest, term and capitalization " +
        "type. \n Please, provide arguments in the following " +
        "format: \n $ " + appname + " amount, interest, term (month), " +
        "capitalization type whitespace separated. \n" +
        "Capitalization type can be: \n " +
        "0 - no capitalization \n " +
        "1 - daily capitalization \n " +
        "2 - weekly capitalization \n " +
        "3 - monthly capitalization \n " +
        "4 - yearly capitalization \n ";
}

bool Calculator::ValidateArgs(int argc, const char** argv) {
    bool isNoArgsProvided = argc == 1;
    if (isNoArgsProvided) {
        std::cout << Help(argv[0]);
        return false;
    }
    bool isEnoughArgs = argc == 5;
    if (!isEnoughArgs) {
        std::cout << Help(argv[0], "Please, provide exactly 4 arguments. \n");
        return false;
    }
    char* end;
    for (int i = 1; i < argc; i++) {
        if (strtod(argv[i], &end) < 0) {
            std::cout << Help(argv[0], "Wrong argument! \n");
            return false;
        } else if (end[0]) {
            std::cout << Help(argv[0], "Wrong number format! \n");
            return false;
        }
    }
    return true;
}

std::string Calculator::operator()(int argc, const char** argv) {
    if (!ValidateArgs(argc, argv))
        return "";
    DepositCalculator calc;
    char* end;
    calc.SetInitialAmount(std::stoi(argv[1]));
    calc.SetAnnualInterest(strtod(argv[2], &end));
    calc.SetTerm(std::stoi(argv[3]));
    calc.SetCapitalization(std::stoi(argv[4]));
    std::string amount = std::to_string(calc.Calculate());
    return amount;
}

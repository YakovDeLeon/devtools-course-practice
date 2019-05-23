// Copyright 2019 Prytov Denis

#include <iostream>

#include "include/currency_calculator.h"

int main(int argc, const char** argv) {
    CurrencyCalculator app;
    std::cout << app(argc, argv);
    return 0;
}

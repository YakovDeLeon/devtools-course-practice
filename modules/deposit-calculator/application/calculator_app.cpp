// Copyright 2019 Vorobev Pavel

#include <iostream>
#include "include/calculator.h"

int main(int argc, const char** argv) {
    Calculator calculator;

    std::cout << calculator(argc, argv);

    return 0;
}

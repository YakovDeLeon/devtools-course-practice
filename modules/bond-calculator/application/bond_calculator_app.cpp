// Copyright 2019 Kutovoi Vadim

#include <stdlib.h>
#include <iostream>
#include <string>

#include "include/bond_calculator_app.h"

int main(int argc, const char** argv) {
    BondCalculatorApp app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}

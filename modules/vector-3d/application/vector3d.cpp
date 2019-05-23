// Copyright 2019 Soluyanov Alexsey

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

#include "include/vector-3d-calculator.h"

int main(int argc, const char** argv) {
    VectorCalculator app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}


// Copyright 2019 Kruglov Yegor

#include <iostream>
#include <string>

#include "include/complex_application.h"

int main(int argc, const char** argv) {
    ComplexApplication app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}

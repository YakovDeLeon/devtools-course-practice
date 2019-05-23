// Copyright 2019 Shkerin Igor

#include <string>
#include <iostream>

#include "include/radix_app.h"

int main(int argc, const char** argv) {
    RadixApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}

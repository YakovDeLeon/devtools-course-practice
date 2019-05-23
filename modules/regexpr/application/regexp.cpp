// Copyright 2019 Iamshchikov Ivan

#include <iostream>

#include "include/regexpr_application.h"

int main(int argc, const char** argv) {
    RegExprApplication regexpr;

    std::cout << regexpr(argc, argv);

    return 0;
}

// Copyright 2019 Savkin Yuriy

#include <iostream>
#include "include/diameter_application.h"

int main(int argc, const char** argv) {
    DiameterApplication app;
    std::cout << app(argc, argv);
    return 0;
}

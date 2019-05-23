// Copyright 2019 Trykin Alexander

#include <iostream>

#include "include/set_application.h"

int main(int argc, char const *argv[]) {
    SetApplication application;
    std::cout << application(argc, argv);
    return 0;
}

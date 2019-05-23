// Copyright 2019 Yakovlev Denis

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/dictionary_application.h"

int main(int argc, const char** argv) {
    DicitonaryApplication app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

// Copyright 2019 Valiullin Damir

#include <string>
#include <iostream>

#include "include/triangles_application.h"

int main(int argc, const char** argv) {
    TrianglesApp app;
    std::string output = app(argc, argv);
    std::cout << output.c_str() << std::endl;
    return 0;
}

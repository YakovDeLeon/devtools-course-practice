// Copyright 2019 Soluyanov Alexsey

#ifndef MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_CALCULATOR_H_
#define MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_CALCULATOR_H_

#include <string>

class VectorCalculator {
 public:
    VectorCalculator();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double x1, y1, z1;
        double x2, y2, z2;
        char operation;
    } Arguments;
};

#endif  // MODULES_VECTOR_3D_INCLUDE_VECTOR_3D_CALCULATOR_H_


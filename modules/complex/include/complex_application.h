// Copyright 2019 Kruglov Yegor

#include <string>

#ifndef MODULES_COMPLEX_INCLUDE_COMPLEX_APPLICATION_H_
#define MODULES_COMPLEX_INCLUDE_COMPLEX_APPLICATION_H_

class ComplexApplication {
 public:
    ComplexApplication() = default;
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool CheckArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double z1_real;
        double z1_imaginary;
        double z2_real;
        double z2_imaginary;
        char operation;
    } Arguments;
};

#endif  // MODULES_COMPLEX_INCLUDE_COMPLEX_APPLICATION_H_

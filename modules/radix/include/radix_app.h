// Copyright 2019 Shkerin Igor

#ifndef MODULES_RADIX_INCLUDE_RADIX_APP_H_
#define MODULES_RADIX_INCLUDE_RADIX_APP_H_

#include <string>

class RadixApp {
 public:
    RadixApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        size_t size;
        char operation;
    } Arguments;
};

#endif  // MODULES_RADIX_INCLUDE_RADIX_APP_H_

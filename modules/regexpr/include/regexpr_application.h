// Copyright 2019 Iamshchikov Ivan

#ifndef MODULES_REGEXPR_INCLUDE_REGEXPR_APPLICATION_H_
#define MODULES_REGEXPR_INCLUDE_REGEXPR_APPLICATION_H_

#include <string>

class RegExprApplication {
 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::string seq;
        std::string str;
    } Arguments;

 public:
    RegExprApplication() = default;

    std::string operator()(int argc, const char **argv);
};

#endif  // MODULES_REGEXPR_INCLUDE_REGEXPR_APPLICATION_H_

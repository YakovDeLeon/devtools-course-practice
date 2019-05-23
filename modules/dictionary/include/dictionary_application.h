// Copyright 2019 Yakovlev Denis

#ifndef MODULES_DICTIONARY_INCLUDE_DICTIONARY_APPLICATION_H_
#define MODULES_DICTIONARY_INCLUDE_DICTIONARY_APPLICATION_H_

#include "include/dictionary.h"

#include <string>
#include <map>

enum class etOperation {
    eSEARCH_ELEMENT = 0,
    eSEARCH_MAX_ELEMENT = 1,
    eSEARCH_MIN_ELEMENT = 2
};

static struct responseHeaderMap : public std::map<std::string, etOperation> {
    responseHeaderMap() {
        this->operator[]("-s") = etOperation::eSEARCH_ELEMENT;
        this->operator[]("-smin") = etOperation::eSEARCH_MIN_ELEMENT;
        this->operator[]("-smax") = etOperation::eSEARCH_MAX_ELEMENT;
    }
    ~responseHeaderMap() {}
} xmap;

class DicitonaryApplication {
 public:
    const char* op_;
    const char* searchElem_;
    DicitonaryApplication() = default;
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const std::string& message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    bool ValidateArguments(int argc, const char** argv);
    std::string message_;
    Dictionary dict_;
};

#endif  // MODULES_DICTIONARY_INCLUDE_DICTIONARY_APPLICATION_H_

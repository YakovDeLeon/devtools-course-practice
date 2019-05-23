// Copyright 2019 Savkin Yuriy

#ifndef MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_APPLICATION_H_
#define MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_APPLICATION_H_

#include <string>
#include "include/diameter.h"

class DiameterApplication {
 private:
    int CastNumber(const char* num);
    int WhatOperation(const char* op);
    std::string HelpInfo();
 public:
    DiameterApplication() = default;
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_DIAMETER_OF_THE_GRAPH_INCLUDE_DIAMETER_APPLICATION_H_

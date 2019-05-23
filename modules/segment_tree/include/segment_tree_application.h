// Copyright 2019 Korobeinikov Aleksey
#ifndef MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_APPLICATION_H_
#define MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_APPLICATION_H_

#include <sstream>
#include <string>
#include "include/segment_tree.h"

class SegmentTreeApplication {
 private:
    std::string Help(const char *appname);
    int ParseOperation(const char **op);
    int ParseValue(const char *val);
    SegmentTree t_;
    std::stringstream answer_;
 public:
    SegmentTreeApplication() :t_(SegmentTree(0, 0)) {}
    std::string operator()(int argc, const char** argv);
};

#endif  // MODULES_SEGMENT_TREE_INCLUDE_SEGMENT_TREE_APPLICATION_H_

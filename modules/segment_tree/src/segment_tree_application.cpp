// Copyright 2019 Korobeinikov Aleksey

#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstring>
#include <string>
#include "include/segment_tree_application.h"

std::string SegmentTreeApplication::Help(const char *appname) {
    return "This is application for segment tree class\n"
        "Please provide arguments in the following format:\n\n"
        "> " + std::string(appname) + " <left border> "
        "<right border> \n" + "Number of function (1=+, 2=min, 3=max)\n"
        "Actions:\n"
        "add1 <index> <value> - add value to elem with index = <index>\n"
        "add2 <left> <right> <value> - add value to segment with "
        "left border = left and right border = right\n"
        "set1 <index> <value> - set value at elem with index = <index>\n"
        "set2 <left> <right> <value> - set value to segment with "
        "left border = left and right border = right\n"
        "get1 <index> - get value at elem with index = <index>\n"
        "get2 <left> <right> - get result of function between "
        "elements with indexes starting with <left> up to <right> index";
}

int SegmentTreeApplication::ParseValue(const char *s) {
    char* end;
    int64_t value = std::strtol(s, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    if (value <= static_cast<int64_t>(std::numeric_limits<int>::min()) ||
        value >= static_cast<int64_t>(std::numeric_limits<int>::max())) {
        throw std::string("Number is out of bounds!");
    }

    return value;
}

int SegmentTreeApplication::ParseOperation(const char **op) {
    if (std::strcmp(*op, "add1") == 0) {
        int index = ParseValue(*(op + 1));
        if (index<t_.GetLeftBarr() || index>t_.GetRightBarr())
            throw std::string("Out of borders!");
        int value = ParseValue(*(op + 2));
        t_.AddValue(index, value);
        return 3;
    }

    if (std::strcmp(*op, "add2") == 0) {
        int l_ = ParseValue(*(op + 1));
        int r_ = ParseValue(*(op + 2));
        if (l_ > r_ || r_ > t_.GetRightBarr() || l_ < t_.GetLeftBarr())
            throw std::string("Incorrect borders");
        int value = ParseValue(*(op + 3));
        t_.AddValue(l_, r_, value);
        return 4;
    }

    if (std::strcmp(*op, "set1") == 0) {
        int index = ParseValue(*(op + 1));
        if (index<t_.GetLeftBarr() || index>t_.GetRightBarr())
            throw std::string("Out of borders!");
        int value = ParseValue(*(op + 2));
        t_.SetValue(index, value);
        return 3;
    }

    if (std::strcmp(*op, "set2") == 0) {
        int l_ = ParseValue(*(op + 1));
        int r_ = ParseValue(*(op + 2));
        if (l_ > r_ || r_ > t_.GetRightBarr() || l_ < t_.GetLeftBarr())
            throw std::string("Incorrect borders");
        int value = ParseValue(*(op + 3));
        t_.SetValue(l_, r_, value);
        return 4;
    }

    if (std::strcmp(*op, "get1") == 0) {
        int index = ParseValue(*(op + 1));
        if (index<t_.GetLeftBarr() || index>t_.GetRightBarr())
            throw std::string("Out of borders!");
        answer_ << "Index = " << index << " Value = "
            << t_.GetValue(index) << std::endl;
        return 2;
    }

    if (std::strcmp(*op, "get2") == 0) {
        int l_ = ParseValue(*(op + 1));
        int r_ = ParseValue(*(op + 2));
        if (l_ > r_ || r_ > t_.GetRightBarr() || l_ < t_.GetLeftBarr())
            throw std::string("Incorrect borders");
        answer_ << "Left border = " << l_ << " Right border = " << r_ <<
            " Value = " << t_.GetValue(l_, r_) << std::endl;
        return 3;
    }
    throw std::string("Unknown operation: ") +
        std::string(*op);
    return 0;
}

std::string SegmentTreeApplication::operator()(int argc, const char** argv) {
    if (argc == 1) {
        return Help(argv[0]);
    }
    if (argc <= 3) {
        return "Minimum 3 arguments"+Help(argv[0]);
    }
    try {
        int left = ParseValue(argv[1]);
        int right = ParseValue(argv[2]);

        if (left > right)
            throw std::string("Wrong borders. Left must be less than right");
        int fun = ParseValue(argv[3]);
        switch (fun) {
          case 1:
            t_ = SegmentTree(left, right);
            break;
          case 2:
            t_ = SegmentTree(left, right, [](int a, int b, int c)->int {
                if (a < b)
                    return a;
                return b;
            }, std::numeric_limits<int>::max());
            break;
          case 3:
            t_ = SegmentTree(left, right, [](int a, int b, int c)->int {
                if (a > b)
                    return a;
                return b;
            }, std::numeric_limits<int>::min());
            break;
        default:
            throw std::string("Wrong number of function!");
            break;
        }

        for (int i = 4; i < argc;) {
            int ch = ParseOperation(argv + i);
            i += ch;
        }
    }
    catch(const std::string& str) {
        return str;
    }
    return answer_.str();
}

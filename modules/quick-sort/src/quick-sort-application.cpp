// Copyright 2019

#include "include/quick-sort.h"
#include "include/quick-sort-application.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

QuickSortApplication::QuickSortApplication() : message_("") {}

void QuickSortApplication::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a quick sort application.\n" +
          "Please provide arguments in the following format:\n\n"+
          "  $ " + appname + " <size of array> " +
           + "<array>\n\n" +
          "Warning!" +
          " All arguments are integers. The array must be sorted.\n";
}

int ParseInt(const char* arg) {
    char* end;
    int value = strtol(arg, &end, 10);
    if (end[0]) {
        throw std::string("Wrong number format!\n\n");
    }
    return value;
}

bool QuickSortApplication::ValidateNumberOfArguments(int argc,
                                                        const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != size + 2) {
            Help(argv[0],
            "ERROR: Check count of arguments and size of entered array.\n\n");
            return false;
        }
    return true;
}

bool CheckSort(const int size, const int* array) {
    int i;
    for (i = 0; i < size - 1; i++)
        if (array[i] > array[i + 1])
            break;

     if (i == size - 1)
        return true;
     else
        return false;
}

std::string QuickSortApplication::operator()(int argc, const char** argv) {
    std::ostringstream stream;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (size < 1) {
        message_ = "ERROR: Size must be >= 1";
        return message_;
    }

    array = new int[size];

    try {
        for (int i = 0; i < size; i++) {
            array[i] = ParseInt(argv[i + 1]);
        }
    } catch(std::string& str) {
        delete[] array;
        return str;
    }

    if (CheckSort(size, array)) {
        QuickSort qs;
        bool result = qs.CheckIncreasing(array, size);;
        if (result == true)
            stream << "Sorted was successful";
    } else {
        stream << "Error! Array not sorted";
    }

    message_ = stream.str();
    delete[] array;

    return message_;
}

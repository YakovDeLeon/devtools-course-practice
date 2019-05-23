// Copyright 2019 Shkerin Igor

#include "include/radix.h"
#include "include/radix_app.h"

#include <string>
#include <cstring>
#include <sstream>
#include <ctime>
#include <random>

RadixApp::RadixApp() : message_() { }

void RadixApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a radix application.\n\n" +

        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <size of array> " +
        " <operation>\n\n" +

        " An array of the size of saz will be created " +
        "and the specified operation will be applied to it.\n\n" +

        "Where size it is positive integer number, " +
        "and <operation> is one of 'RadixSort', 'HowMuchMem'\n\n";
}

bool RadixApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 3) {
        help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "RadixSort") == 0) {
        op = 's';
    } else if (strcmp(arg, "HowMuchMem") == 0) {
        op = 'm';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string RadixApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.size = parseDouble(argv[1]);
        args.operation = parseOperation(argv[2]);
        Radix rdx(args.size);
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(-100000000, 100000000);

        int* _array = new int[args.size];
        for (size_t i = 0; i < args.size; ++i) {
            _array[i] = distribution(generator);
        }

        clock_t t1, t2;
        double time_result;

        std::ostringstream stream;
        switch (args.operation) {
        case 's':
            t1 = clock();
            rdx.RadixSort(_array, args.size);
            t2 = clock();
            time_result = (t2 - t1 + .0) / CLOCKS_PER_SEC;

            stream << "Array size " << args.size << " sorted by RadixSort.\n";
            stream << "Time spent on sorting : " << time_result;
            break;
        case 'm':
            stream << "The amount of occupied memory = " << rdx.HowMuchMem();
            break;
        }
        message_ = stream.str();
        delete[] _array;
        return message_;
    }
    catch (std::string & str) {
        return str;
    }
}

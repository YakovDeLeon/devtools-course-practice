// Copyright 2019 Kruglov Yegor

#include "include/complex.h"
#include "include/complex_application.h"

#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <sstream>

void ComplexApplication::Help(const char* appname, const char* message) {
    message_ = std::string(message) +
        "This is a complex number calculator application. \n\n" +
        "Please, provide arguments in the following format: \n\n "
        "  $ " + appname + " <z1_real> <z1_imaginary> " +
        "<operation> <z2_real> <z2_imaginary> \n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of '+', '-', '*', '/'.\n";
}

bool ComplexApplication::CheckArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 6) {
        Help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("ERROR: Wrong number format!");
    }

    return value;
}

char ParseOperation(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else {
        throw std::string("ERROR: Wrong operation format!");
    }
    return op;
}

std::string ComplexApplication::operator()(int argc, const char** argv) {
    Arguments args;

    if (!CheckArguments(argc, argv)) {
        return message_;
    }
    try {
        args.z1_real = ParseDouble(argv[1]);
        args.z1_imaginary = ParseDouble(argv[2]);
        args.z2_real = ParseDouble(argv[4]);
        args.z2_imaginary = ParseDouble(argv[5]);
        args.operation = ParseOperation(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    Complex z1;
    Complex z2;

    z1.set_re(args.z1_real);
    z1.set_im(args.z1_imaginary);
    z2.set_re(args.z2_real);
    z2.set_im(args.z2_imaginary);
    std::ostringstream stream;
    switch (args.operation) {
    case '+':
        z1 += z2;
        stream << "Real = " << z1.get_re() << " "
            << "Imaginary = " << z1.get_im();
        break;
    case '-':
        z1 -= z2;
        stream << "Real = " << z1.get_re() << " "
            << "Imaginary = " << z1.get_im();
        break;
    case '*':
        z1 *= z2;
        stream << "Real = " << z1.get_re() << " "
            << "Imaginary = " << z1.get_im();
        break;
    case '/':
        try {
            z1 /= z2;
            stream << "Real = " << z1.get_re() << " "
                << "Imaginary = " << z1.get_im();
            break;
        }
        catch (std::string& str) {
            return str;
        }
    }
    message_ = stream.str();
    return message_;
}

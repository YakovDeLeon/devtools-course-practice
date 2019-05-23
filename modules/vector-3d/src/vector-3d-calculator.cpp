// Copyright 2019 Soluyanov Alexsey

#include "include/vector_3d.h"
#include "include/vector-3d-calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

VectorCalculator::VectorCalculator() : message_("") {}

void VectorCalculator::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a vector-3d calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <x1> <y1> <z1> " +
          "<x2> <y2> <z2> <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of '+', '-', '*' or 'cross'.\n" +
          "or $ <x1> <y1> <z1> <operation> where operation = norma" +
          "or normalize" +
          "or $ <x1> <y1> <z1> <number> <operation> where operation" +
          "is one of '*', '/'.\n\n";
}

bool VectorCalculator::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5 && argc != 8 && argc != 6) {
        help(argv[0], "ERROR: Incorrect num of arguments.\n\n");
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
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "norma") == 0) {
        op = 'n';
    } else if (strcmp(arg, "/") == 0) {
        op = '/';
    } else if (strcmp(arg, "cross") == 0) {
        op = 'c';
    } else if (strcmp(arg, "normalize") == 0) {
        op = 'z';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string VectorCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        if (argc == 8) {
            args.x1 = parseDouble(argv[1]);
            args.y1 = parseDouble(argv[2]);
            args.z1 = parseDouble(argv[3]);
            args.x2 = parseDouble(argv[4]);
            args.y2 = parseDouble(argv[5]);
            args.z2 = parseDouble(argv[6]);
            args.operation = parseOperation(argv[7]);
        } else if (argc == 5) {
            args.x1 = parseDouble(argv[1]);
            args.y1 = parseDouble(argv[2]);
            args.z1 = parseDouble(argv[3]);
            args.operation = parseOperation(argv[4]);
        } else if (argc == 6) {
            args.x1 = parseDouble(argv[1]);
            args.y1 = parseDouble(argv[2]);
            args.z1 = parseDouble(argv[3]);
            args.x2 = parseDouble(argv[4]);
            args.operation = parseOperation(argv[5]);
        }
    }
    catch(std::string& str) {
        return str;
    }
    Vector3d v1;
    Vector3d v2;
    double var;
    if (argc == 8) {
        v1.setX(args.x1);
        v1.setY(args.y1);
        v1.setZ(args.z1);
        v2.setX(args.x2);
        v2.setY(args.y2);
        v2.setZ(args.z2);
    } else if (argc == 6) {
        v1.setX(args.x1);
        v1.setY(args.y1);
        v1.setZ(args.z1);
        var = args.x2;
    } else if (argc == 5) {
        v1.setX(args.x1);
        v1.setY(args.y1);
        v1.setZ(args.z1);
    }
    std::ostringstream stream;
    if (argc == 8) {
        Vector3d v;
        double res;
        switch (args.operation) {
         case '+':
             v = v1 + v2;
             stream << "X = " << v.getX() << " "
                   << "Y = " << v.getY() << " "
                   << "Z = " << v.getZ() << "\n";
            break;
         case '-':
             v = v1 - v2;
             stream << "X = " << v.getX() << " "
                   << "Y = " << v.getY() << " "
                   << "Z = " << v.getZ() << "\n";
            break;
         case '*':
             res = v1 * v2;
             stream << "Result = " << res << "\n";
            break;
         case 'c':
             v = v1.Cross(v2);
             stream << "X = " << v.getX() << " "
                   << "Y = " << v.getY() << " "
                   << "Z = " << v.getZ() << "\n";
            break;
        }
    } else if (argc == 5) {
        double res;
        Vector3d v;
        switch (args.operation) {
         case 'n':
             res = v1.Norma();
             stream << "Result = " << res << "\n";
            break;
         case 'z':
            try {
             v = v1.Normalize();
             stream << "X = " << v.getX() << " "
                   << "Y = " << v.getY() << " "
                   << "Z = " << v.getZ() << "\n";
            break;
            }
            catch(std::string& str) {
                return str;
            }
        }
    } else if (argc == 6) {
         Vector3d v;
         switch (args.operation) {
          case '*':
              v = v1 * var;
              stream << "X = " << v.getX() << " "
                    << "Y = " << v.getY() << " "
                    << "Z = " << v.getZ() << "\n";
             break;
          case '/':
             try {
              v = v1 / var;
              stream << "X = " << v.getX() << " "
                    << "Y = " << v.getY() << " "
                    << "Z = " << v.getZ() << "\n";
             break;
             }
             catch(std::string& str) {
                 return str;
             }
         }
    }
    message_ = stream.str();
    return message_;
}


// Copyright 2019 Valiullin Damir

#include "include/triangles.h"
#include "include/triangles_application.h"

#include <string>
#include <cstring>
#include <sstream>

TrianglesApp::TrianglesApp() : message_() { }

void TrianglesApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a triangles application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <x1> <y1> " +
        "<x2> <y2> <x3> <y3> <operation>\n\n" +

        "Where all arguments are double-precision numbers, " +
        "and <operation> is one of 'points', 'angles', " +
        "'sides', 'perimeter', 'square'.\n";
}

bool TrianglesApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 8) {
        help(argv[0], "ERROR: Should be 7 arguments.\n\n");
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
    if (strcmp(arg, "points") == 0) {
        op = 'p';
    } else if (strcmp(arg, "angles") == 0) {
        op = 'a';
    } else if (strcmp(arg, "sides") == 0) {
        op = 's';
    } else if (strcmp(arg, "perimeter") == 0) {
        op = 'P';
    } else if (strcmp(arg, "square") == 0) {
        op = 'S';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string TrianglesApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.x1 = parseDouble(argv[1]);
        args.y1 = parseDouble(argv[2]);
        args.x2 = parseDouble(argv[3]);
        args.y2 = parseDouble(argv[4]);
        args.x3 = parseDouble(argv[5]);
        args.y3 = parseDouble(argv[6]);
        args.operation = parseOperation(argv[7]);

        Point a(args.x1, args.y1);
        Point b(args.x2, args.y2);
        Point c(args.x3, args.y3);

        Triangle tr(a, b, c);

        std::ostringstream stream;
        switch (args.operation) {
        case 'p':
            stream << "A(" << args.x1 << ", " << args.y1 << ") ";
            stream << "B(" << args.x2 << ", " << args.y2 << ") ";
            stream << "C(" << args.x3 << ", " << args.y3 << ")";
            break;
        case 'a':
            stream << "Angle A = " << tr.get_angle_a() << " ";
            stream << "Angle B = " << tr.get_angle_b() << " ";
            stream << "Angle C = " << tr.get_angle_c();
            break;
        case 's':
            stream << "AB = " << tr.SideLength(a, b) << " ";
            stream << "AC = " << tr.SideLength(a, c) << " ";
            stream << "BC = " << tr.SideLength(b, c);
            break;
        case 'P':
            stream << "Perimeter = " << tr.Perimeter();
            break;
        case 'S':
            stream << "Square = " << tr.Square();
            break;
        }

        message_ = stream.str();
        return message_;
    }
    catch (std::string& str) {
        return str;
    }
}

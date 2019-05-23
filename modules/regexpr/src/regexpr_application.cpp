// Copyright 2019 Iamshchikov Ivan

#include "include/regexpr.h"
#include "include/regexpr_application.h"

#include <string>
#include <cstring>
#include <sstream>

void RegExprApplication::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a regular expression application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        " $ " + appname + " <seq> " +
        "<str>" +
        "Where <seq> is regular expression\n"
        "<str> is search string.\n";
}

bool RegExprApplication::ValidateNumberOfArguments(int argc,
                                                   const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 3) {
        Help(argv[0], "ERROR: Should be 2 arguments.\n\n");
        return false;
    }
    return true;
}

std::string RegExprApplication::operator()(int argc, const char **argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }

    args.seq = argv[1];
    args.str = argv[2];

    RegExpr re(args.seq);

    std::ostringstream stream;

    auto res = re.Match(args.str);

    if (res.first == -1 && res.second == -1)
        stream << "Search string doesn't contain a line according to pattern: "
               << args.seq;
    else
        stream << "Position of start = " << res.first << " "
               << "Position of end = " << res.second;

    message_ = stream.str();

    return message_;
}

// Copyright 2019 Kutovoi Vadim

#include "include/bond_calculator.h"
#include "include/bond_calculator_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

BondCalculatorApp::BondCalculatorApp() : message_("") {}

void BondCalculatorApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a bond calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <price> <nominal_price> " +
          "<months> <year> <percentage> <current_year> " +
          "<current_month> <metric>\n\n";
}

bool BondCalculatorApp::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 8) {
        Help(argv[0], "ERROR: Should be 7 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string ParseMetric(const char* arg) {
    std::string op;
    if (strcmp(arg, "all") == 0) {
        op = "all";
    } else if (strcmp(arg, "total") == 0) {
        op = "total";
    } else if (strcmp(arg, "payments") == 0) {
        op = "payments";
    } else if (strcmp(arg, "relative") == 0) {
        op = "relative";
    } else if (strcmp(arg, "yearly") == 0) {
        op = "yearly";
    } else {
        throw std::string("Wrong metric!");
    }
    return op;
}

std::string BondCalculatorApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.price         = ParseDouble(argv[1]);
        args.nominal_price = ParseDouble(argv[2]);
        args.year          = ParseDouble(argv[3]);
        args.percentage    = ParseDouble(argv[4]);
        args.current_year  = ParseDouble(argv[5]);
        args.current_month = ParseDouble(argv[6]);
        args.metric        = ParseMetric(argv[7]);
    }
    catch(std::string& str) {
        return str;
    }

    BondCalculator bcalc;
    bond bond_;
    std::vector<int> mnths = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    bond_.price = args.price;
    bond_.nominal_price = args.nominal_price;
    bond_.year = args.year;
    bond_.percentage = args.percentage;
    bond_.months = mnths;

    std::ostringstream stream;

    if (args.metric == "all") {
        std::vector<payment> payments =
          bcalc.CalculatePayments(bond_,
                     args.current_month,
                     args.current_year);
        payment totalIncome =
          bcalc.CalculateTotalIncome(bond_,
                        args.current_month,
                        args.current_year);

        stream << "Payments : " << std::endl;
        for (auto i : payments) {
            stream << "\tYear : " << i.year <<
                " Month : " << i.month <<
                " Value : " << i.value << std::endl;
        }

        stream << "Relative income : " << std::endl <<
            "\t" <<
            bcalc.CalculateRelativeIncome(bond_,
                             args.current_month,
                             args.current_year)
            << std::endl;

        stream << "Total Income : " << std::endl <<
            "\tYear : " << totalIncome.year << std::endl <<
            "\tMonth : " << totalIncome.month << std::endl <<
            "\tValue : " << totalIncome.value << std::endl;

        stream << "Yearly internal income :" << std::endl <<
            "\t" <<
            bcalc.CalculateYearlyInternalIncome(bond_,
                                    args.current_year)
            << std::endl;
    } else if (args.metric == "payments") {
        std::vector<payment> payments =
          bcalc.CalculatePayments(bond_,
                     args.current_month,
                     args.current_year);

        stream << "Payments : " << std::endl;
        for (auto i : payments) {
            stream << "\tYear : " << i.year <<
                " Month : " << i.month <<
                " Value : " << i.value << std::endl;
        }
    } else if (args.metric == "relative") {
        stream << "Relative income : " << std::endl <<
            "\t" <<
            bcalc.CalculateRelativeIncome(bond_,
                             args.current_month,
                             args.current_year)
            << std::endl;
    } else if (args.metric == "yearly") {
        stream << "Yearly internal income :" << std::endl <<
            "\t" <<
            bcalc.CalculateYearlyInternalIncome(bond_,
                                    args.current_year)
            << std::endl;
    } else if (args.metric == "total") {
        payment totalIncome =
          bcalc.CalculateTotalIncome(bond_,
                        args.current_month,
                        args.current_year);

        stream << "Total income : " << std::endl <<
            "\tYear : " << totalIncome.year << std::endl <<
            "\tMonth : " << totalIncome.month << std::endl <<
            "\tValue : " << totalIncome.value << std::endl;
    }

    message_ = stream.str();

    return message_;
}

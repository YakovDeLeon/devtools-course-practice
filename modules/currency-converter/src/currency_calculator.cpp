// Copyright 2019 Prytov Denis

#include "include/currency_converter.h"
#include "include/currency_calculator.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

void CurrencyCalculator::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a currency calculator application.\n" +
          "Please provide arguments in the following format:\n"+

          "  $ " + appname + " <value> <operation>\n" +

          "Value have to be a double-precision number, " +
          "and <operation> is one of the following:\n" +
          "'RubleToDollar',\n" +
          "'RubleToEuro',\n" +
          "'RubleToShekel',\n" +
          "'RubleToGrivna',\n" +
          "'RubleToDirham',\n" +
          "'DollarToRubles',\n" +
          "'DollarToEuro',\n" +
          "'DollarToGrivna',\n" +
          "'DollarToShekel',\n" +
          "'DollarToDirham',\n" +
          "'EuroToDollar',\n" +
          "'EuroToRubles',\n" +
          "'EuroToShekel',\n" +
          "'EuroToDirham',\n" +
          "'EuroToGrivna',\n" +
          "'ShekelToRubles',\n" +
          "'ShekelToDirham',\n" +
          "'ShekelToEuro',\n" +
          "'ShekelToDollar',\n" +
          "'ShekelToGrivna',\n" +
          "'DirhamToRubles',\n" +
          "'DirhamToEuro',\n" +
          "'DirhamToShekel',\n" +
          "'DirhamToDollar',\n" +
          "'DirhamToGrivna',\n" +
          "'GrivnaToRubles',\n" +
          "'GrivnaToEuro',\n" +
          "'GrivnaToDirham',\n" +
          "'GrivnaToShekel',\n" +
          "'GrivnaToDollar'.\n";
}

bool CurrencyCalculator::ValidateNumberOfArgs(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 3) {
        Help(argv[0], "ERROR: Should be 2 arguments.\n");
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

std::string parseOperation(const char* arg) {
    std::string op;
    if (strcmp(arg, "RubleToDollar") == 0) {
        op = "RubleToDollar";
    } else if (strcmp(arg, "RubleToEuro") == 0) {
        op = "RubleToEuro";
    } else if (strcmp(arg, "RubleToShekel") == 0) {
        op = "RubleToShekel";
    } else if (strcmp(arg, "RubleToGrivna") == 0) {
        op = "RubleToGrivna";
    } else if (strcmp(arg, "RubleToDirham") == 0) {
        op = "RubleToDirham";
    } else if (strcmp(arg, "DollarToRubles") == 0) {
        op = "DollarToRubles";
    } else if (strcmp(arg, "DollarToEuro") == 0) {
        op = "DollarToEuro";
    } else if (strcmp(arg, "DollarToGrivna") == 0) {
        op = "DollarToGrivna";
    } else if (strcmp(arg, "DollarToShekel") == 0) {
        op = "DollarToShekel";
    } else if (strcmp(arg, "DollarToDirham") == 0) {
        op = "DollarToDirham";
    } else if (strcmp(arg, "EuroToDollar") == 0) {
        op = "EuroToDollar";
    } else if (strcmp(arg, "EuroToRubles") == 0) {
        op = "EuroToRubles";
    } else if (strcmp(arg, "EuroToShekel") == 0) {
        op = "EuroToShekel";
    } else if (strcmp(arg, "EuroToDirham") == 0) {
        op = "EuroToDirham";
    } else if (strcmp(arg, "EuroToGrivna") == 0) {
        op = "EuroToGrivna";
    } else if (strcmp(arg, "ShekelToRubles") == 0) {
        op = "ShekelToRubles";
    } else if (strcmp(arg, "ShekelToDirham") == 0) {
        op = "ShekelToDirham";
    } else if (strcmp(arg, "ShekelToEuro") == 0) {
        op = "ShekelToEuro";
    } else if (strcmp(arg, "ShekelToDollar") == 0) {
        op = "ShekelToDollar";
    } else if (strcmp(arg, "ShekelToGrivna") == 0) {
        op = "ShekelToGrivna";
    } else if (strcmp(arg, "DirhamToRubles") == 0) {
        op = "DirhamToRubles";
    } else if (strcmp(arg, "DirhamToEuro") == 0) {
        op = "DirhamToEuro";
    } else if (strcmp(arg, "DirhamToShekel") == 0) {
        op = "DirhamToShekel";
    } else if (strcmp(arg, "DirhamToDollar") == 0) {
        op = "DirhamToDollar";
    } else if (strcmp(arg, "DirhamToGrivna") == 0) {
        op = "DirhamToGrivna";
    } else if (strcmp(arg, "GrivnaToRubles") == 0) {
        op = "GrivnaToRubles";
    } else if (strcmp(arg, "GrivnaToEuro") == 0) {
        op = "GrivnaToEuro";
    } else if (strcmp(arg, "GrivnaToDirham") == 0) {
        op = "GrivnaToDirham";
    } else if (strcmp(arg, "GrivnaToShekel") == 0) {
        op = "GrivnaToShekel";
    } else if (strcmp(arg, "GrivnaToDollar") == 0) {
        op = "GrivnaToDollar";
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string CurrencyCalculator::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArgs(argc, argv)) {
        return message_;
    }
    try {
        args.value      = parseDouble(argv[1]);
        args.operation    = parseOperation(argv[2]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;

    if (args.operation == "RubleToDollar") {
        stream << "Dollar: " << CurrencyConverter::RubleToDollar(args.value);
    } else if (args.operation == "RubleToEuro") {
        stream << "Euro: " << CurrencyConverter::RubleToEuro(args.value);
    } else if (args.operation == "RubleToShekel") {
        stream << "Shekel: " << CurrencyConverter::RubleToShekel(args.value);
    } else if (args.operation == "RubleToGrivna") {
        stream << "Grivna: " << CurrencyConverter::RubleToGrivna(args.value);
    } else if (args.operation == "RubleToDirham") {
        stream << "Dirham: " << CurrencyConverter::RubleToDirham(args.value);
    } else if (args.operation == "DollarToRubles") {
        stream << "Rubles: " << CurrencyConverter::DollarToRubles(args.value);
    } else if (args.operation == "DollarToEuro") {
        stream << "Euro: " << CurrencyConverter::DollarToEuro(args.value);
    } else if (args.operation == "DollarToGrivna") {
        stream << "Grivna: " << CurrencyConverter::DollarToGrivna(args.value);
    } else if (args.operation == "DollarToShekel") {
        stream << "Shekel: " << CurrencyConverter::DollarToShekel(args.value);
    } else if (args.operation == "DollarToDirham") {
        stream << "Dirham: " << CurrencyConverter::DollarToDirham(args.value);
    } else if (args.operation == "EuroToDollar") {
        stream << "Dollar: " << CurrencyConverter::EuroToDollar(args.value);
    } else if (args.operation == "EuroToRubles") {
        stream << "Rubles: " << CurrencyConverter::EuroToRubles(args.value);
    } else if (args.operation == "EuroToShekel") {
        stream << "Shekel: " << CurrencyConverter::EuroToShekel(args.value);
    } else if (args.operation == "EuroToDirham") {
        stream << "Dirham: " << CurrencyConverter::EuroToDirham(args.value);
    } else if (args.operation == "EuroToGrivna") {
        stream << "Grivna: " << CurrencyConverter::EuroToGrivna(args.value);
    } else if (args.operation == "ShekelToRubles") {
        stream << "Rubles: " << CurrencyConverter::ShekelToRubles(args.value);
    } else if (args.operation == "ShekelToDirham") {
        stream << "Dirham: " << CurrencyConverter::ShekelToDirham(args.value);
    } else if (args.operation == "ShekelToEuro") {
        stream << "Euro: " << CurrencyConverter::ShekelToEuro(args.value);
    } else if (args.operation == "ShekelToDollar") {
        stream << "Dollar: " << CurrencyConverter::ShekelToDollar(args.value);
    } else if (args.operation == "ShekelToGrivna") {
        stream << "Grivna: " << CurrencyConverter::ShekelToGrivna(args.value);
    } else if (args.operation == "DirhamToRubles") {
        stream << "Rubles: " << CurrencyConverter::DirhamToRubles(args.value);
    } else if (args.operation == "DirhamToEuro") {
        stream << "Euro: " << CurrencyConverter::DirhamToEuro(args.value);
    } else if (args.operation == "DirhamToShekel") {
        stream << "Shekel: " << CurrencyConverter::DirhamToShekel(args.value);
    } else if (args.operation == "DirhamToDollar") {
        stream << "Dollar: " << CurrencyConverter::DirhamToDollar(args.value);
    } else if (args.operation == "DirhamToGrivna") {
        stream << "Grivna: " << CurrencyConverter::DirhamToGrivna(args.value);
    } else if (args.operation == "GrivnaToRubles") {
        stream << "Rubles: " << CurrencyConverter::GrivnaToRubles(args.value);
    } else if (args.operation == "GrivnaToEuro") {
        stream << "Euro: " << CurrencyConverter::GrivnaToEuro(args.value);
    } else if (args.operation == "GrivnaToDirham") {
        stream << "Dirham: " << CurrencyConverter::GrivnaToDirham(args.value);
    } else if (args.operation == "GrivnaToShekel") {
        stream << "Shekel: " << CurrencyConverter::GrivnaToShekel(args.value);
    } else if (args.operation == "GrivnaToDollar") {
        stream << "Dollar: " << CurrencyConverter::GrivnaToDollar(args.value);
    }

    message_ = stream.str();

    return message_;
}

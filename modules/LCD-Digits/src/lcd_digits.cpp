// Copyright 2019 Vikhrev Ivan
#include <string>
#include <algorithm>
#include "include/lcd_digits.h"

const std::string LCDDigits::point[3] = { " ",
                                          " ",
                                          "."};

const std::string LCDDigits::colon[3] = {" ",
                                         ".",
                                         "." };

const std::string LCDDigits::zero[3] = {" _ ",
                                        "| |",
                                        "|_|"};

const std::string LCDDigits::one[3] = {" ",
                                       "|",
                                       "|"};

const std::string LCDDigits::two[3] = {" _ ",
                                       " _|",
                                       "|_ "};

const std::string LCDDigits::three[3] = {" _ ",
                                         " _|",
                                         " _|"};

const std::string LCDDigits::four[3] = {"   ",
                                        "|_|",
                                        "  |"};

const std::string LCDDigits::five[3] = {" _ ",
                                        "|_ ",
                                        " _|"};

const std::string LCDDigits::six[3] = {" _ ",
                                       "|_ ",
                                       "|_|"};

const std::string LCDDigits::seven[3] = {" _ ",
                                         "  |",
                                         "  |"};

const std::string LCDDigits::eight[3] = {" _ ",
                                         "|_|",
                                         "|_|"};

const std::string LCDDigits::nine[3] = { " _ ",
                                         "|_|",
                                         " _|"};

std::string LCDDigits::Decompose(const int& n) {
    int num = n;
    std::string number = "";
    do {
        number += std::to_string(num % 10);
        num /= 10;
    } while (num > 0);
    std::reverse(number.begin(), number.end());
    return number;
}

std::string LCDDigits::LCDStr(const std::string& s) {
    std::string lcdN = "";
    for (unsigned int line = 0; line < 3; line++) {
        for (unsigned int i = 0; i < s.length(); i++) {
            switch (s[i]) {
                case '0':
                    lcdN += zero[line];
                    break;
                case '1':
                    lcdN += one[line];
                    break;
                case '2':
                    lcdN += two[line];
                    break;
                case '3':
                    lcdN += three[line];
                    break;
                case '4':
                    lcdN += four[line];
                    break;
                case '5':
                    lcdN += five[line];
                    break;
                case '6':
                    lcdN += six[line];
                    break;
                case '7':
                    lcdN += seven[line];
                    break;
                case '8':
                    lcdN += eight[line];
                    break;
                case '9':
                    lcdN += nine[line];
                    break;
                case ':':
                    lcdN += colon[line];
                    break;
                case '.':
                    lcdN += point[line];
                    break;
                default:
                    throw "Invalid Symbol";
                    break;
            }
            lcdN += " ";
        }
        lcdN += "\n";
    }
    return lcdN;
}

std::string LCDDigits::LCD(const int& n) {
    std::string number = Decompose(n);
    return LCDStr(number);
}

std::string LCDDigits::LCD(const std::string& s) {
    return LCDStr(s);
}

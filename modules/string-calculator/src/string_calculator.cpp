// Copyright 2019 Kruglov Yegor

#include "include/string_calculator.h"

#include <math.h>

#include <iostream>
#include <string>

void StringCalculator::set_infix(const std::string str) {
    infix_ = str;
}

std::string StringCalculator::get_infix() {
    return infix_;
}

std::string StringCalculator::get_postfix() {
    return postfix_;
}

bool StringCalculator::Check() {
    while (!charStack_.empty()) {
        charStack_.pop();
    }
    int sizeOfInfix = static_cast<int>(infix_.size());
    for (int i = 0; i < sizeOfInfix; i++) {
        switch (infix_[i]) {
            case '(':
            {
                charStack_.push(infix_[i]);
                break;
            }
            case ')':
            {
                if (charStack_.empty()) {
                    return false;
                } else {
                    charStack_.pop();
                    break;
                }
            }
            case '+':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix_[i - 1] == '-' || infix_[i - 1] == '+')
                    return false;
                else if (infix_[i - 1] == '*' || infix_[i - 1] == '/')
                    return false;
                else if (infix_[i - 1] == '^')
                    return false;
                break;
            }
            case '-':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix_[i - 1] == '-' || infix_[i - 1] == '+')
                    return false;
                else if (infix_[i - 1] == '*' || infix_[i - 1] == '/')
                    return false;
                else if (infix_[i - 1] == '^')
                    return false;
                break;
            }
            case '*':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix_[i - 1] == '-' || infix_[i - 1] == '+')
                    return false;
                else if (infix_[i - 1] == '*' || infix_[i - 1] == '/')
                    return false;
                else if (infix_[i - 1] == '^')
                    return false;
                break;
            }
            case '/':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix_[i - 1] == '-' || infix_[i - 1] == '+')
                    return false;
                else if (infix_[i - 1] == '*' || infix_[i - 1] == '/')
                    return false;
                else if (infix_[i - 1] == '^')
                    return false;
                break;
            }
            case '^':
            {
                if (i == 0 || i == sizeOfInfix - 1)
                    return false;
                if (infix_[i - 1] == '-' || infix_[i - 1] == '+')
                    return false;
                else if (infix_[i - 1] == '*' || infix_[i - 1] == '/')
                    return false;
                else if (infix_[i - 1] == '^')
                    return false;
                break;
            }
        }
    }
    if (charStack_.empty()) {
        return true;
    } else {
        return false;
    }
}

int StringCalculator::Priority(const char& el) {
    switch (el) {
        case '(':
        {
            return 0;
        }
        case '+':
        {
            return 1;
        }
        case '-':
        {
            return 1;
        }
        case '*':
        {
            return 2;
        }
        case '/':
        {
            return 2;
        }
        case '^':
        {
            return 3;
        }
    }
    return -1;
}

int StringCalculator::get_priority(const char& el) {
    return Priority(el);
}

void StringCalculator::ToPostfix() {
    if (Check()) {
        std::string tmp = '(' + infix_ + ')';
        int sizeOfTmp = static_cast<int>(tmp.size());
        for (int i = 0; i < sizeOfTmp; i++) {
            if (tmp[i] == '(') {
                charStack_.push(tmp[i]);
            }
            if ((tmp[i] >= '0' && tmp[i] <= '9') || (tmp[i] == '.')) {
                postfix_ += tmp[i];
            }
            if (tmp[i] == ')') {
                char el = charStack_.top();
                charStack_.pop();
                while (el != '(') {
                    postfix_ += el;
                    el = charStack_.top();
                    charStack_.pop();
                }
            }
            if ((tmp[i] == '+') || (tmp[i] == '-') || (tmp[i] == '*') ||
                (tmp[i] == '/') || (tmp[i] == '^')) {
                postfix_ += " ";
                while (Priority(tmp[i]) <= Priority(charStack_.top())) {
                    postfix_ += charStack_.top();
                    charStack_.pop();
                }
                charStack_.push(tmp[i]);
            }
        }
    } else {
        throw std::string("Incorrect data");
    }
}

double StringCalculator::Calculate() {
    while (!doubleStack_.empty()) {
        doubleStack_.pop();
    }
    ToPostfix();
    int sizeOfPostfix = static_cast<int>(postfix_.size());
    for (int i = 0; i < sizeOfPostfix; i++) {
        if (postfix_[i] == '+' || postfix_[i] == '-' || postfix_[i] == '*' ||
            postfix_[i] == '/' || postfix_[i] == '^') {
            double res, op1, op2 = doubleStack_.top();
            doubleStack_.pop();
            if (doubleStack_.empty()) {
                throw std::string("Error - Incorrect Data");
            }
            op1 = doubleStack_.top();
            doubleStack_.pop();
            switch (postfix_[i]) {
                case '+':
                {
                    res = op1 + op2;
                    break;
                }
                case '-':
                {
                    res = op1 - op2;
                    break;
                }
                case '*':
                {
                    res = op1 * op2;
                    break;
                }
                case '/':
                {
                    if (op2 == 0) {
                        throw std::string("Error - division by zero");
                    }
                    res = op1 / op2;
                    break;
                }
                case '^':
                {
                    res = pow(op1, op2);
                    break;
                }
            }
            doubleStack_.push(res);
        }
        if ((postfix_[i] >= '0' && postfix_[i] <= '9') || postfix_[i] == '.') {
            char *tmp;
            double res;
            res = strtod(&postfix_[i], &tmp);
            int j = tmp - &postfix_[i];
            i += j - 1;
            doubleStack_.push(res);
        }
    }
    return doubleStack_.top();
}

void StringCalculator::set_stacks(int n) {
    for (int i = 0; i < n; i++) {
        charStack_.push('+');
        doubleStack_.push(2.5);
    }
}

void StringCalculator::set_postfix(const std::string str) {
    postfix_ = str;
}

// Copyright 2019 Kruglov Yegor

#include <stack>
#include <string>

#ifndef MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_
#define MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

class StringCalculator{
 private:
    std::string infix_, postfix_;
    std::stack<char> charStack_;
    std::stack<double> doubleStack_;

    bool Check();
    int Priority(const char& el);
    void ToPostfix();

 public:
    void set_infix(const std::string str);
    void set_postfix(const std::string str);
    void set_stacks(int n);
    std::string get_infix();
    std::string get_postfix();
    int get_priority(const char& el);

    double Calculate();
};

#endif  // MODULES_STRING_CALCULATOR_INCLUDE_STRING_CALCULATOR_H_

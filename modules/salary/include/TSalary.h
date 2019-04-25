// Copyright Irina Astafeva 2019

#ifndef MODULES_SALARY_INCLUDE_TSALARY_H_
#define MODULES_SALARY_INCLUDE_TSALARY_H_

#include <string>
#include <iostream>

class TSalary {
 private:
    int salary_;       // in month
    int norm_;         // hours in month
    int overtime_;     // hours in month
    int vacantion_;    // hours in month
    int worked_hours_;  // hors in month
 public:
    TSalary(int _salary, int _norm,
            int _worked_hours, int _overtime,
            int _vacantion);
    double Payroll();
};

#endif  // MODULES_SALARY_INCLUDE_TSALARY_H_

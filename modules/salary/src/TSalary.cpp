// Copyright Irina Astafeva 2019

#include <string>
#include <iostream>
#include "include/TSalary.h"

TSalary::TSalary(int _salary, int _norm,
                 int _worked_hours, int _overtime,
                 int _vacantion) {
    bool wrong_data = _salary <= 0 || _norm <= 0 ||
        _worked_hours < 0 || _overtime < 0 ||
        _vacantion < 0 ||
        _worked_hours + _overtime - _vacantion < 0;
    if (wrong_data) {
        throw std::string("Invalid value");
    }
    salary_ = _salary;
    norm_ = _norm;
    overtime_ = _overtime;
    vacantion_ = _vacantion;
    worked_hours_ = _worked_hours;
}

double TSalary::Payroll() {
    double fact = worked_hours_ + overtime_ - vacantion_;
    return static_cast<double>(salary_) * fact / static_cast<double>(norm_);
}

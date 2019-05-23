// Copyright 2019 Utkin Konstantin

#include "include/quadratic_equation.h"

#include <iostream>
#include <cmath>

double QuadraticEquation::Discriminant() const {
    return coef_b_ * coef_b_ - 4 * coef_a_ * coef_c_;
}

QuadraticEquation::QuadraticEquation(double a, double b, double c):
    coef_a_(a), coef_b_(b), coef_c_(c) {
    if (a == 0.0 && b == 0.0)
        throw "It is not a quadratic equation";
}

double QuadraticEquation::GetX1() const {
    double x;
    double d = Discriminant();

    if (d < 0.0)
        throw "No real solutions";

    if (coef_a_ == 0.0)
        x = -coef_c_ / coef_b_;
    else
        x = (-coef_b_ + sqrt(d)) / (2 * coef_a_);
    return x;
}

double QuadraticEquation::GetX2() const {
    double x;
    double d = Discriminant();

    if (d < 0.0)
        throw "No real solutions";

    if (coef_a_ == 0.0)
        x = -coef_c_ / coef_b_;
    else
        x = (-coef_b_ - sqrt(d)) / (2 * coef_a_);
    return x;
}

std::ostream& operator<<(std::ostream &out,
    const QuadraticEquation qe) {
    out << qe.coef_a_ << "*x^2 + " <<
        qe.coef_b_ << "*x + " << qe.coef_c_ <<
            " = 0" << std::endl;
    return out;
}

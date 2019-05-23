// Copyright 2019 Utkin Konstantin

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

#include <iostream>

class QuadraticEquation {
 private:
    double coef_a_;
    double coef_b_;
    double coef_c_;

    double Discriminant() const;

 public:
    explicit QuadraticEquation(double a, double b, double c);

    double GetX1() const;
    double GetX2() const;

    friend std::ostream& operator<<(std::ostream &out,
        const QuadraticEquation qe);
};
#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

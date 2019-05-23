// Copyright 2019 Yakovlev Pavel

#include <cmath>

#include "include/numeric_integrate.h"

NumericIntegrate::NumericIntegrate() {
    a = 0.0;
    b = 1.0;
}

NumericIntegrate::NumericIntegrate(double _a, double _b) {
    if (_a < _b) {
        a = _a;
        b = _b;
    } else {
        b = _a;
        a = _b;
    }
}

double NumericIntegrate::FunctionValue(double x) const {
    double res = 0.0;
    if (x < 0) {
        res = -sqrt(-x);
    } else {
        res = sqrt(x);
    }
    return res;
}

void NumericIntegrate::Set_a(double _a) {
    if (_a <= b) {
        a = _a;
    } else {
        a = b;
        b = _a;
    }
}

void NumericIntegrate::Set_b(double _b) {
    if (_b >= a) {
        b = _b;
    } else {
        b = a;
        a = _b;
    }
}

void NumericIntegrate::SetSection(double _a, double _b) {
    if (_a < _b) {
        a = _a;
        b = _b;
    } else {
        b = _a;
        a = _b;
    }
}

double NumericIntegrate::Get_a() const {
    return a;
}

double NumericIntegrate::Get_b() const {
    return b;
}

double NumericIntegrate::RectangleMethod(int n) {
    double h = (b-a)/n;
    double res = 0.0;
    if (a == b) return 0.0;
    for (int i = 0; i < n; i++) {
        double middle = ((a+i*h)+(a+(i+1)*h))/2.0;
        res += FunctionValue(middle)*h;
    }
    return res;
}

double NumericIntegrate::TrapeziumMethod(int n) {
    double h = (b-a)/n;
    double res = 0.0;
    if (a == b) return 0.0;

    for (int i = 0; i < n; i++) {
        res += (FunctionValue(a+i*h) + FunctionValue(a+(i+1)*h))*h/2.0;
    }
    return res;
}

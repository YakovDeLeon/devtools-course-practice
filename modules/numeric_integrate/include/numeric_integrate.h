// Copyright 2019 Yakovlev Pavel

#ifndef MODULES_NUMERIC_INTEGRATE_INCLUDE_NUMERIC_INTEGRATE_H_
#define MODULES_NUMERIC_INTEGRATE_INCLUDE_NUMERIC_INTEGRATE_H_

class NumericIntegrate {
    double a;
    double b;
 public:
    NumericIntegrate();
    NumericIntegrate(double _a, double _b);
    double FunctionValue(double x) const;
    void Set_a(double _a);
    void Set_b(double _b);
    double Get_a() const;
    double Get_b() const;
    void SetSection(double _a, double _b);
    double RectangleMethod(int n = 64);
    double TrapeziumMethod(int n = 64);
};

#endif  // MODULES_NUMERIC_INTEGRATE_INCLUDE_NUMERIC_INTEGRATE_H_

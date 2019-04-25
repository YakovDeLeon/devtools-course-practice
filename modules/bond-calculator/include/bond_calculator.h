// Copyright 2019 Kudrin Matvey

#include<vector>
#include<cmath>
#include<algorithm>


struct bond {
    double price;
    double nominal_price;
    std::vector<int> months;
    int year;
    double percentage;
};

struct payment {
    double value;
    int month;
    int year;
};

#ifndef MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_H_
#define MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_H_


class BondCalculator {
 public:
    BondCalculator() = default;
    BondCalculator(BondCalculator&&) = default;

    std::vector<payment> CalculatePayments(const bond &paper, int current_month,
            int current_year);

    payment CalculateTotalIncome(const bond &paper, int current_month,
            int current_year);

    double CalculateYearlyInternalIncome(const bond paper, int current_year);
    double CalculateRelativeIncome(const bond &paper, int current_month,
            int current_year);
};

#endif  // MODULES_BOND_CALCULATOR_INCLUDE_BOND_CALCULATOR_H_

// Copyright 2019 Sitkin Dmitry

#include "include/deposit_calculator.h"

#include <string>


int DepositCalculator::GetInitialAmount() {
    return initial_amount_;
}
int DepositCalculator::GetTerm() {
    return term_;
}
double DepositCalculator::GetAnnualInterest() {
    return annual_interest_;
}
int DepositCalculator::GetCapitalization() {
    return capitalization_;
}

void DepositCalculator::SetInitialAmount(int initial_amount) {
    initial_amount_ = initial_amount;
}
void DepositCalculator::SetTerm(int term) {
    term_ = term;
}
void DepositCalculator::SetAnnualInterest(double annual_interest) {
    annual_interest_ = annual_interest;
}
void DepositCalculator::SetCapitalization(int capitalization) {
    capitalization_ = capitalization;
}

double DepositCalculator::Calculate() {
    double sum;
    double temp = 1.0;
    int num_of_operation = 0;
    int num_of_capitalization = 0;

    switch (capitalization_) {
    case 0:
        sum = initial_amount_ * (1 + (annual_interest_ * term_) / 1200);
        break;
    case 1:
        temp = 1.0;
        num_of_capitalization = 1;
        num_of_operation = term_ * 30;
        for (int i = 0; i < num_of_operation; i++)
            temp *= 1 + (annual_interest_ * num_of_capitalization) / 36500;
        sum = initial_amount_ * temp;
        break;
    case 2:
        temp = 1.0;
        num_of_capitalization = 7;
        num_of_operation = term_ * 30 / 7;
        for (int i = 0; i < num_of_operation; i++)
            temp *= 1 + (annual_interest_ * num_of_capitalization) / 36500;
        sum = initial_amount_ * temp;
        break;
    case 3:
        temp = 1.0;
        num_of_capitalization = 1;
        num_of_operation = term_;
        for (int i = 0; i < num_of_operation; i++)
            temp *= 1 + (annual_interest_ * num_of_capitalization) / 1200;
        sum = initial_amount_ * temp;
        break;
    case 4:
        temp = 1.0;
        num_of_capitalization = 1;
        num_of_operation = term_ / 12;
        for (int i = 0; i < num_of_operation; i++)
            temp *= 1 + (annual_interest_ * num_of_capitalization) / 100;
        sum = initial_amount_ * temp;
        break;
    default:
        throw std::string("Wrong type");
        break;
    }
    return sum;
}


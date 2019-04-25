// Copyright 2019 Vorobev Pavel

#include "include/mortgage_calculator.h"

#include <cmath>
#include <string>
#include <iostream>


double MortgageCalculator::CalculatePayments(int sum, int first_payment,
    int credit_term, int annual_interest_rate) {

    double monthly_interest_rate =
        ConvertToMonthlyInterestRate(annual_interest_rate);
    monthly_payment_ =
        CalculateAnnuityRate(monthly_interest_rate, credit_term) * sum;
    return monthly_payment_;
}

double MortgageCalculator::ConvertToMonthlyInterestRate(int interest_rate) {
    return static_cast<double>(interest_rate) / (12 * 100);
}

double MortgageCalculator::CalculateAnnuityRate(double interest_rate,
        int credit_term) {
    return interest_rate * pow(1 + interest_rate, credit_term)
        / (pow(1 + interest_rate, credit_term) - 1);
}

int MortgageCalculator::CalculateLoanOverpayment(int monthly_payment,
        int credit_term, int sum) {
    return static_cast<int> (monthly_payment * credit_term - sum);
}

double MortgageCalculator::GetCalculatedMonthlyPayment() {
    if (monthly_payment_ < 0) {
        return 0.0;
    } else {
        return monthly_payment_;
    }
}

// Copyright 2019 Sadikov Artem

#include "include/arrears_service.h"

#include <cmath>
#include <string>

ArrearService::ArrearService(const int debt, const int procent,
                             const int rate, const int time) :
                             debt_(debt), procent_(procent),
                             rate_(rate), time_(time) {
    SetExpress();
    yearpay_ = debt_ / Fond();
}

ArrearService::ArrearService(const ArrearService& obj) {
    debt_ = obj.debt_;
    procent_ = obj.procent_;
    express_ = obj.express_;
    rate_ = obj.rate_;
    time_ = obj.time_;
}

double ArrearService::ExpressPay() {
    return debt_* (rate_ * 0.01) + debt_ / Fond();
}

double ArrearService::YearPayVal(double prog) {
    double result;
    double val1, val2_1, val2, val2_2;

    val1 = 1.0 / Fond();
    val2_2 = pow(1 + procent_ * 0.01, time_);
    val2_1 = val2_2 - (1 + time_ * (procent_ * 0.01));
    val2 =  val2_1 / pow(procent_ * 0.01, 2);

    result = val1 * (debt_ - prog * val2);

    return result;
}

double ArrearService::Fond() {
    double result;

    result = (pow(1 + procent_ * 0.01, time_) - 1) / (procent_ * 0.01);

    return result;
}

void ArrearService::SetYearPay(double prog) {
    if (prog == 0)
        throw std::string("No progression to calculate year pay");

    yearpay_ = YearPayVal(prog);
}

void ArrearService::SetDebt(const int debt) {
    if (debt <= 0)
        throw std::string("No debt to serv");

    debt_ = debt;
}

void ArrearService::SetProcent(const int procent) {
    if (procent <= 0)
        throw std::string("Invalid procent");

    procent_ = procent;
}

void ArrearService::SetRate(const int rate) {
    rate_ = rate;
}

void ArrearService::SetTime(const int time) {
    if (time <= 0)
        throw std::string("No time to service");

    time_ = time;
}

void ArrearService::SetExpress() {
    if (procent_ <= 0)
        throw std::string("Invalid procent");
    if (time_ <= 0)
        throw std::string("Invalid time");

    express_ = ExpressPay();
}

double ArrearService::GetExpress() {
    return express_;
}

double ArrearService::GetDebt() {
    return debt_;
}

double ArrearService::GetYearPay() {
    return yearpay_;
}

int ArrearService::GetProcent() {
    return procent_;
}

int ArrearService::GetTime() {
    return time_;
}

int ArrearService::GetRate() {
    return rate_;
}

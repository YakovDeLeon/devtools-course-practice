// Copyright 2019 Pinaev Danil

#include "include/fraction.h"

#include <math.h>

#include <string>

int Fraction::Nod(int a, int b) const {
    a = std::abs(a);
    b = std::abs(b);

    while (a && b) {
        if (a >= b)
            a %= b;
        else
            b %= a;
    }
    return a | b;
}

Fraction::Fraction() : numerator_(0), denominator_(1) {}

Fraction::Fraction(const int numerator, const int denominator)
                   : numerator_(numerator) {
    if (denominator == 0)
        throw std::string("Denominator can't be a zero");
    else
        denominator_ = denominator;
}

Fraction::Fraction(const Fraction& z)
                             : numerator_(z.GetNum()),
                            denominator_(z.GetDen()) {}

Fraction& Fraction::operator=(const Fraction& z) {
    numerator_ = z.GetNum();
    denominator_ = z.GetDen();

    return *this;
}

int Fraction::GetNum() const {
    return numerator_;
}

int Fraction::GetDen() const {
    return denominator_;
}

void Fraction::SetNum(const int numerator) {
    numerator_ = numerator;
}

void Fraction::SetDen(const int denominator) {
    if (denominator == 0)
        throw std::string("Denominator can't be a zero");
    denominator_ = denominator;
}

Fraction Fraction::operator+(const Fraction& z) const {
    Fraction sum;
    int numerator;
    int denominator;
    int nod;

    numerator = this->GetNum() * z.GetDen() +
                    z.GetNum() * this->GetDen();
    denominator = this->GetDen() * z.GetDen();
    nod = sum.Nod(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    sum.SetNum(numerator);
    sum.SetDen(denominator);

    return sum;
}

Fraction Fraction::operator-(const Fraction& z) const {
    Fraction difference;
    int numerator;
    int denominator;
    int nod;

    numerator = this->GetNum() * z.GetDen() -
                    z.GetNum() * this->GetDen();
    denominator = this->GetDen() * z.GetDen();
    nod = difference.Nod(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    difference.SetNum(numerator);
    difference.SetDen(denominator);

    return difference;
}

Fraction Fraction::operator*(const Fraction& z) const {
    Fraction multiplication;
    int numerator;
    int denominator;
    int nod;

    numerator = this->GetNum() * z.GetNum();
    denominator = this->GetDen() * z.GetDen();
    nod = multiplication.Nod(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    multiplication.SetNum(numerator);
    multiplication.SetDen(denominator);

    return multiplication;
}

Fraction Fraction::operator/(const Fraction& z) const {
    Fraction division;
    int numerator;
    int denominator;
    int nod;

    numerator = this->GetNum() * z.GetDen();
    denominator = this->GetDen() * z.GetNum();
    nod = division.Nod(numerator, denominator);

    numerator /= nod;
    denominator /= nod;

    division.SetNum(numerator);
    division.SetDen(denominator);

    return division;
}

bool Fraction::EqualsZero(const Fraction& z) const {
    return z.numerator_ == 0;
}

bool Fraction::operator == (const Fraction& z) const {
    return EqualsZero(Fraction(*this) - z);
}

bool Fraction::operator != (const Fraction& z) const {
    return !EqualsZero(Fraction(*this) - z);
}

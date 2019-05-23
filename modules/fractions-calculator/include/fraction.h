// Copyright 2019 Pinaev Danil

#ifndef MODULES_FRACTIONS_CALCULATOR_INCLUDE_FRACTION_H_
#define MODULES_FRACTIONS_CALCULATOR_INCLUDE_FRACTION_H_

class Fraction {
 public:
    Fraction();
    Fraction(const int numerator, const int denominator);
    Fraction(const Fraction& z);

    Fraction& operator=(const Fraction& z);

    int Nod(const int a, const int b) const;
    int GetNum() const;
    int GetDen() const;
    void SetNum(const int numerator);
    void SetDen(const int denominator);

    Fraction operator + (const Fraction& z) const;
    Fraction operator - (const Fraction& z) const;
    Fraction operator * (const Fraction& z) const;
    Fraction operator / (const Fraction& z) const;

    bool EqualsZero(const Fraction& z) const;

    bool operator == (const Fraction& z) const;
    bool operator != (const Fraction& z) const;

 private:
    int numerator_;
    int denominator_;
};

#endif  // MODULES_FRACTIONS_CALCULATOR_INCLUDE_FRACTION_H_

// Copyright 2019 Malkin Danil

#ifndef MODULES_POLYNOMS_INCLUDE_MONOM_H_
#define MODULES_POLYNOMS_INCLUDE_MONOM_H_

#include <string>
#include <map>

class Monom {
 public:
    Monom();
    explicit Monom(double c);

    Monom(const Monom& rhs);
    explicit Monom(double c, std::map<char, double> vars);

    Monom& operator=(const Monom& z);

    std::string ToString();

    bool operator==(const Monom& rhs) const;
    bool operator!=(const Monom& rhs) const;

 private:
    Monom operator+(const Monom& rhs);
    Monom operator-(const Monom& rhs);
    Monom operator*(const Monom& rhs);
    Monom operator/(const Monom& rhs);

    bool EqualsVariabels(const Monom& r) const;

    std::map<char, double> variables_;
    double coefficient_;

    friend class Polynom;
};
#endif  // MODULES_POLYNOMS_INCLUDE_MONOM_H_

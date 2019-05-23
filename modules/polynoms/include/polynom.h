// Copyright 2019 Malkin Danil

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOMS_INCLUDE_POLYNOM_H_

#include <string>
#include <vector>
#include <map>

class Monom;

class Polynom {
 public:
    Polynom();
    explicit Polynom(double coff);
    Polynom(const Polynom& rhs);
    explicit Polynom(const std::vector<Monom>& mons);
    explicit Polynom(const Monom& mon);

    Polynom& operator=(const Polynom& z);

    void AddMonom(const Monom& m);
    std::string ToString();

    bool operator==(const Polynom& rhs) const;
    bool operator!=(const Polynom& rhs) const;

    Polynom operator+(const Polynom& rhs);
    Polynom operator-(const Polynom& rhs);
    Polynom operator*(const Polynom& rhs);
    Polynom operator/(const Monom& m);

    double CalculateResult(const std::map<char, double>& in_params);

 private:
    int Contains(const std::vector<Monom>& vec, const Monom& m) const;

    std::vector<Monom> monoms_;
};
#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOM_H_

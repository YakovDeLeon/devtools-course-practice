// Copyright 2019 Malkin Danil

#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <vector>
#include <map>

#include "include/monom.h"
#include "include/polynom.h"

Polynom::Polynom() : monoms_() {
}

Polynom::Polynom(double coff) {
    if (coff != 0.0) monoms_.emplace_back(Monom(coff));
}

Polynom::Polynom(const Polynom & rhs) : monoms_(rhs.monoms_) {
}
Polynom::Polynom(const std::vector<Monom> & buf) : monoms_(buf) {
}
Polynom::Polynom(const Monom & buf) : monoms_({ buf }) {
}

Polynom & Polynom::operator=(const Polynom & z) {
    monoms_ = z.monoms_;
    return *this;
}

void Polynom::AddMonom(const Monom & m) {
    for (auto& mm : monoms_) {
        if (mm.variables_ == m.variables_) {
            mm.coefficient_ += m.coefficient_;
            return;
        }
    }
    monoms_.push_back(m);
}

std::string Polynom::ToString() {
    std::stringstream ss;
    for (size_t i = 0; i < monoms_.size() - 1; ++i)
        ss << "(" << monoms_[i].ToString() << ") + ";
    if (monoms_.size() > 0)
        ss << "(" << monoms_[monoms_.size() - 1].ToString() << ")";
    return ss.str();
}

bool Polynom::operator==(const Polynom & rhs) const {
    if (monoms_.size() != rhs.monoms_.size())
        return false;
    for (size_t i = 0; i < monoms_.size(); ++i) {
        bool cont = false;
        for (size_t j = 0; j < rhs.monoms_.size(); j++)
            if (monoms_[i] == rhs.monoms_[j]) {
                cont = true;
                break;
            }
        if (!cont) return false;
    }
    return true;
}

bool Polynom::operator!=(const Polynom & rhs) const {
    return !(*this == rhs);
}

Polynom Polynom::operator+(const Polynom & rhs) {
    Polynom tmp(*this);
    for (size_t j = 0; j < rhs.monoms_.size(); j++) {
        int ind = Contains(tmp.monoms_, rhs.monoms_[j]);
        if (ind > -1)
            tmp.monoms_[ind] = (tmp.monoms_[ind] + rhs.monoms_[j]);
        else
            tmp.monoms_.push_back(rhs.monoms_[j]);
    }
    return tmp;
}

Polynom Polynom::operator-(const Polynom & rhs) {
    Polynom tmp(*this);
    for (size_t j = 0; j < rhs.monoms_.size(); j++) {
        int ind = Contains(tmp.monoms_, rhs.monoms_[j]);
        if (ind > -1) {
            auto t = (tmp.monoms_[ind] - rhs.monoms_[j]);
            if (t.coefficient_ != 0.0)
                tmp.monoms_[ind] = t;
            else
                tmp.monoms_.erase(tmp.monoms_.begin() + ind);
        } else {
            tmp.monoms_.push_back(Monom(-1.0) * rhs.monoms_[j]);
        }
    }
    return tmp;
}

Polynom Polynom::operator*(const Polynom & rhs) {
    Polynom tmp;
    for (size_t i = 0; i < monoms_.size(); i++) {
        for (size_t j = 0; j < rhs.monoms_.size(); j++) {
            Monom t = monoms_[i] * rhs.monoms_[j];
            if (t.coefficient_ != 0.0)
                tmp.monoms_.emplace_back(t);
        }
    }
    return tmp;
}

Polynom Polynom::operator/(const Monom & m) {
    Polynom tmp;
    for (size_t i = 0; i < monoms_.size(); i++) {
        Monom t = monoms_[i] / m;
        if (!std::isnan(t.coefficient_))
            tmp.monoms_.emplace_back(t);
    }
    return tmp;
}

double Polynom::CalculateResult(const std::map<char, double>& in_params) {
    double res = 0.0;
    for (const auto& m : monoms_) {
        double tmp = m.coefficient_;
        for (const auto& in_var : in_params) {
            auto m_var = m.variables_.find(in_var.first);
            if (m_var != m.variables_.end()) {
                tmp *= std::pow(in_var.second, (*m_var).second);
            }
        }
        res += tmp;
    }
    return res;
}

int Polynom::Contains(const std::vector<Monom>& vec, const Monom & m) const {
    for (size_t i = 0; i < vec.size(); i++)
        if (vec[i].variables_ == m.variables_) return i;
    return -1;
}

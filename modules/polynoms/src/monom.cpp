// Copyright 2019 Malkin Danil

#include <sstream>
#include <set>
#include <cmath>
#include <string>
#include <map>

#include "include/monom.h"

Monom::Monom() : coefficient_(1.0) {
}

Monom::Monom(double c) : coefficient_(c) {
}

Monom::Monom(const Monom & rhs) :
    variables_(rhs.variables_),
    coefficient_(rhs.coefficient_) {
}

Monom::Monom(double c, std::map<char, double> vars) : variables_(vars),
coefficient_(c) {
}

Monom & Monom::operator=(const Monom & z) {
    variables_ = z.variables_;
    coefficient_ = z.coefficient_;
    return *this;
}

std::string Monom::ToString() {
    std::stringstream ss;
    ss << coefficient_;
    for (auto& v : variables_) {
        if (v.second != 0.0) {
            ss << v.first;
            ss << '^';
            ss << v.second;
        }
    }
    return ss.str();
}

bool Monom::operator==(const Monom & rhs) const {
    if (std::abs(coefficient_ - rhs.coefficient_) != 0) return false;
    return EqualsVariabels(rhs);
}

bool Monom::operator!=(const Monom & rhs) const {
    return !(*this == rhs);
}

Monom Monom::operator+(const Monom & rhs) {
    Monom tmp(*this);
    if (EqualsVariabels(rhs)) {
        tmp.coefficient_ += rhs.coefficient_;
    }
    return tmp;
}

Monom Monom::operator-(const Monom & rhs) {
    Monom tmp(*this);
    if (EqualsVariabels(rhs)) {
        tmp.coefficient_ -= rhs.coefficient_;
    }
    return tmp;
}

Monom Monom::operator*(const Monom & rhs) {
    Monom ret(*this);
    ret.coefficient_ *= rhs.coefficient_;
    for (auto& var : rhs.variables_) {
        auto rv = ret.variables_.find(var.first);
        if (rv == ret.variables_.end()) {
            ret.variables_.insert(var);
        } else {
            ret.variables_[var.first] += var.second;
        }
    }
    return ret;
}

Monom Monom::operator/(const Monom & rhs) {
    if (rhs.coefficient_ == 0.0)
        throw std::string("Can't divide by zero");
    Monom ret(*this);
    ret.coefficient_ /= rhs.coefficient_;
    for (auto& var : rhs.variables_) {
        auto rv = ret.variables_.find(var.first);
        if (rv == ret.variables_.end()) {
            auto tmp = var;
            tmp.second *= -1;
            ret.variables_.insert(tmp);
        } else {
            ret.variables_[var.first] -= var.second;
            if (ret.variables_[var.first] == 0.0) {
                auto it = ret.variables_.find(var.first);
                ret.variables_.erase(it);
            }
        }
    }
    return ret;
}

bool Monom::EqualsVariabels(const Monom& r) const {
    for (auto& var : variables_) {
        auto rv = r.variables_.find(var.first);
        if (rv == r.variables_.end() || (*rv).second != var.second) {
            return false;
        }
    }
    return true;
}

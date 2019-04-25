// Copyright 2019 Bykovskaya Alina

#include "include/romanumber.h"
#include <iostream>
#include <string>

std::string RomaNumber::RomaConvert(int n, int rank) {
    if (rank == 4) {
        switch (n) {
            case 1: return "M"; break;
            case 2: return "MM"; break;
            case 3: return "MMM"; break;
        }
    } else if (rank == 3) {
        switch (n) {
            case 1: return "C"; break;
            case 2: return "CC"; break;
            case 3: return "CCC"; break;
            case 4: return "CD"; break;
            case 5: return "D"; break;
            case 6: return "DC"; break;
            case 7: return "DCC"; break;
            case 8: return "DCCC"; break;
            case 9: return "CM"; break;
        }
    } else if (rank == 2) {
        switch (n) {
        case 1: return "X"; break;
        case 2: return "XX"; break;
        case 3: return "XXX"; break;
        case 4: return "XL"; break;
        case 5: return "L"; break;
        case 6: return "LX"; break;
        case 7: return "LXX"; break;
        case 8: return "LXXX"; break;
        case 9: return "XC"; break;
        }
    } else if (rank == 1) {
        switch (n) {
        case 1: return "I"; break;
        case 2: return "II"; break;
        case 3: return "III"; break;
        case 4: return "IV"; break;
        case 5: return "V"; break;
        case 6: return "VI"; break;
        case 7: return "VII"; break;
        case 8: return "VIII"; break;
        case 9: return "IX"; break;
        }
    }
    return "";
}

void RomaNumber::ArabToRoma(int ar) {
    if (ar < 0 || ar > 3999)
        throw "Wrong number";
    arabic_ = ar;
    roma_ = "";
    for (int i = 1; (ar != 0 && i < 5); ++i) {
        roma_ = RomaConvert(ar % 10, i) + roma_;
        ar /= 10;
    }
}

void RomaNumber::RomaToArab(std::string ro) {
    int _ar = 0;
    int n = ro.length();
    for (int i = 0; i < n; ++i) {
        char t = ro[i];
        if (t == 'I') {
            if (ro[i + 1] == 'V' || ro[i + 1] == 'X')
                _ar -= 1;
            else
                _ar += 1;
        } else if (t == 'V') {
            _ar += 5;
        } else if (t == 'X') {
            if (ro[i + 1] == 'L' || ro[i + 1] == 'C')
                _ar -= 10;
            else
                _ar += 10;
        } else if (t == 'L') {
            _ar += 50;
        } else if (t == 'C') {
            if (ro[i + 1] == 'D' || ro[i + 1] == 'M')
                _ar -= 100;
            else
                _ar += 100;
        } else if (t == 'D') {
            _ar += 500;
        } else if (t == 'M') {
            _ar += 1000;
        }
    }
    roma_ = ro;
    arabic_ = _ar;
}

RomaNumber::RomaNumber(int ar) {
    ArabToRoma(ar);
}

RomaNumber::RomaNumber(std::string ro) {
    if (!IsStringCorrect(ro))
        throw "Wrong string";
    else
        RomaToArab(ro);
}

bool RomaNumber::IsStringCorrect(std::string ro) {
    int n = ro.length();
    for (int i = 0; i < n; ++i) {
        bool flag = (ro[i] == 'I' || ro[i] == 'V' ||
            ro[i] == 'X' || ro[i] == 'L' ||
            ro[i] == 'C' || ro[i] == 'D' ||
            ro[i] == 'M');
        if (!flag)
            return false;
    }
    return true;
}

std::ostream& operator<<(std::ostream &out, const RomaNumber a) {
    out << a.arabic_ << " = " << a.roma_ << std::endl;
    return out;
}

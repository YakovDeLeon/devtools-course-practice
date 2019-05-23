// Copyright 2019 Prytov Denis

#ifndef MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
#define MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_

class CurrencyConverter {
 public:
    static double RubleToDollar(const double &Rub) {
        return Rub / 64.82;
    }
    static double RubleToEuro(const double &Rub) {
        return Rub / 72.29;
    }
    static double RubleToShekel(const double &Rub) {
        return Rub / 17.9;
    }
    static double RubleToGrivna(const double &Rub) {
        return Rub / 2.45;
    }
    static double RubleToDirham(const double &Rub) {
        return Rub / 17.65;
    }
    static double DollarToRubles(const double &Dol) {
        return Dol * 64.82;
    }
    static double DollarToEuro(const double &Dol) {
        return Dol * 0.89;
    }
    static double DollarToGrivna(const double &Dol) {
        return Dol * 26.47;
    }
    static double DollarToShekel(const double &Dol) {
        return Dol * 3.62;
    }
    static double DollarToDirham(const double &Dol) {
        return Dol * 3.67;
    }
    static double EuroToDollar(const double &Euro) {
        return Euro * 1.11;
    }
    static double EuroToRubles(const double &Euro) {
        return Euro * 72.24;
    }
    static double EuroToShekel(const double &Euro) {
        return Euro * 4.03;
    }
    static double EuroToDirham(const double &Euro) {
        return Euro * 4.09;
    }
    static double EuroToGrivna(const double &Euro) {
        return Euro * 29.53;
    }
    static double ShekelToRubles(const double &Shekel) {
        return Shekel * 17.88;
    }
    static double ShekelToDirham(const double &Shekel) {
        return Shekel * 1.01;
    }
    static double ShekelToEuro(const double &Shekel) {
        return Shekel * 0.246;
    }
    static double ShekelToDollar(const double &Shekel) {
        return Shekel * 0.276;
    }
    static double ShekelToGrivna(const double &Shekel) {
        return Shekel * 7.31;
    }
    static double DirhamToRubles(const double &Dir) {
        return Dir * 17.63;
    }
    static double DirhamToEuro(const double &Dir) {
        return Dir * 0.243;
    }
    static double DirhamToShekel(const double &Dir) {
        return Dir * 0.98;
    }
    static double DirhamToDollar(const double &Dir) {
        return Dir * 0.273;
    }
    static double DirhamToGrivna(const double &Dir) {
        return Dir * 7.20;
    }
    static double GrivnaToRubles(const double &Grivna) {
        return Grivna * 2.443;
    }
    static double GrivnaToEuro(const double &Grivna) {
        return Grivna * 0.033;
    }
    static double GrivnaToDirham(const double &Grivna) {
        return Grivna * 0.138;
    }
    static double GrivnaToShekel(const double &Grivna) {
        return Grivna * 0.136;
    }
    static double GrivnaToDollar(const double &Grivna) {
        return Grivna * 0.037;
    }
};

#endif  // MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_

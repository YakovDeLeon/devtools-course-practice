// Copyright 2019 Prytov Denis

#ifndef MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_
#define MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

class MassConverter {
 public:
    static double TonsToKilograms(const double &tons) {
        return tons * 1000;
    }
    static double TonsToGrams(const double &tons) {
        return tons * 1000000;
    }
    static double TonsToMilligrams(const double &tons) {
        return tons * 1000000000;
    }
    static double TonsToPounds(const double &tons) {
        return tons * 2204.623;
    }
    static double TonsToOunces(const double &tons) {
        return tons * 35274.962;
    }
    static double KilogramsToTons(const double &kg) {
        return kg / 1000;
    }
    static double KilogramsToGrams(const double &kg) {
        return kg * 1000;
    }
    static double KilogramsToMilligrams(const double &kg) {
        return kg * 1000000;
    }
    static double KilogramsToPounds(const double &kg) {
        return kg * 2.205;
    }
    static double KilogramsToOunces(const double &kg) {
        return kg * 35.274;
    }
    static double GramsToTons(const double &g) {
        return g / 1000000;
    }
    static double GramsToKilograms(const double &g) {
        return g / 1000;
    }
    static double GramsToMilligrams(const double &g) {
        return g * 1000;
    }
    static double GramsToPounds(const double &g) {
        return g / 453.592;
    }
    static double GramsToOunces(const double &g) {
        return g / 28.35;
    }
    static double MilligramsToTons(const double &mg) {
        return mg / 1000000000;
    }
    static double MilligramsToKilograms(const double &mg) {
        return mg / 1000000;
    }
    static double MilligramsToGrams(const double &mg) {
        return mg / 1000;
    }
    static double MilligramsToPounds(const double &mg) {
        return mg / 453592.37;
    }
    static double MilligramsToOunces(const double &mg) {
        return mg / 28349.523;
    }
    static double PoundsToTons(const double &lbs) {
        return lbs / 2204.623;
    }
    static double PoundsToKilograms(const double &lbs) {
        return lbs / 2.205;
    }
    static double PoundsToGrams(const double &lbs) {
        return lbs * 453.592;
    }
    static double PoundsToMilligrams(const double &lbs) {
        return lbs * 453592.37;
    }
    static double PoundsToOunces(const double &lbs) {
        return lbs * 16;
    }
    static double OuncesToTons(const double &oz) {
        return oz / 35273.962;
    }
    static double OuncesToKilograms(const double &oz) {
        return oz / 35.274;
    }
    static double OuncesToGrams(const double &oz) {
        return oz * 28.35;
    }
    static double OuncesToMilligrams(const double &oz) {
        return oz * 28349.523;
    }
    static double OuncesToPounds(const double &oz) {
        return oz / 16;
    }
};

#endif  // MODULES_MASS_CONVERTER_INCLUDE_MASS_CONVERTER_H_

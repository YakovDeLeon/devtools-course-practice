// Copyright 2019 Kholobko Vladimir

#ifndef MODULES_CONVECTOR_LENGTH_INCLUDE_CONVECTOR_H_
#define MODULES_CONVECTOR_LENGTH_INCLUDE_CONVECTOR_H_

class Convector {
 public:
    static double MMinCM(const double &MM) {
        return MM / 10;
    }
    static double MMinDM(const double &MM) {
        return MM / 100;
    }
    static double MMinM(const double &MM) {
        return MM / 1000;
    }
    static double MMinKM(const double &MM) {
        return MM / 1000000;
    }
    static double CMinMM(const double &CM) {
        return CM * 10;
    }
    static double CMinDM(const double &CM) {
        return CM / 10;
    }
    static double CMinM(const double &CM) {
        return CM / 1000;
    }
    static double CMinKM(const double &CM) {
        return CM / 100000;
    }
    static double DMinMM(const double &DM) {
        return DM * 100;
    }
    static double DMinCM(const double &DM) {
        return DM * 10;
    }
    static double DMinM(const double &DM) {
        return DM /10;
    }
    static double DMinKM(const double &DM) {
        return DM / 10000;
    }
    static double MinMM(const double &M) {
        return M * 1000;
    }
    static double MinCM(const double &M) {
        return M * 100;
    }
    static double MinDM(const double &M) {
        return M * 10;
    }
    static double MinKM(const double &M) {
        return M / 10;
    }
    static double KMinMM(const double &KM) {
        return KM * 1000000;
    }
    static double KMinCM(const double &KM) {
        return KM * 100000;
    }
    static double KMinDM(const double &KM) {
        return KM * 10000;
    }
    static double KMinM(const double &KM) {
        return KM * 100;
    }
};

#endif  // MODULES_CONVECTOR_LENGTH_INCLUDE_CONVECTOR_H_

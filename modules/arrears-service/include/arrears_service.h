// Copyright 2019 Sadikov Artem

#ifndef MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_
#define MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_

class ArrearService {
 public:
    ArrearService(const int debt, const int procent,
                  const int rate, const int time);
    ArrearService(const ArrearService& obj);

    void SetYearPay(double prog);
    void SetExpress();
    void SetDebt(const int debt);
    void SetProcent(const int procent);
    void SetRate(const int rate);
    void SetTime(const int time);
    double GetYearPay();
    double GetExpress();
    double GetDebt();
    int GetProcent();
    int GetRate();
    int GetTime();

    double Fond();

 private:
    double YearPayVal(double prog);
    double ExpressPay();
    int debt_;
    double express_;
    int procent_;
    double yearpay_;
    int rate_;
    int time_;
};

#endif  // MODULES_ARREARS_SERVICE_INCLUDE_ARREARS_SERVICE_H_

// Copyright 2019 Balynin Alexey

#ifndef MODULES_STACK_INCLUDE_TDATACOM_H_
#define MODULES_STACK_INCLUDE_TDATACOM_H_

const int DataOK = 0;
const int DataErr = -1;

class TDataCom {
 protected:
    int RetCode;
    int SetRetCode(int ret) { return RetCode = ret; }
 public:
    TDataCom(): RetCode(DataOK) {}
    virtual ~TDataCom() {}
    int GetRetCode() {
        int temp = RetCode;
        RetCode = DataOK;
        return temp;
    }
};

#endif  // MODULES_STACK_INCLUDE_TDATACOM_H_

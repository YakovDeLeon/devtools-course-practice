// Copyright 2019 Muravev Denis

#ifndef MODULES_BIG_INT_INCLUDE_BIG_INT_H_
#define MODULES_BIG_INT_INCLUDE_BIG_INT_H_

#include <string>
#include <cstdint>
#define NSB 1000000000
// NSB - Number Systems Base
// Using number systems with base 1 000 000 000

class BigInt {
 private:
    int size;
    int size_mem;
    char sign;
    int * mem;

    int realSize();
    void removingZeros();

 public:
    explicit BigInt(int_fast64_t bi = 0, int _sizeMem = 1);
    BigInt(const BigInt & bi);
    explicit BigInt(const std::string & st);
    ~BigInt();

    BigInt & operator = (const BigInt & bi);
    BigInt & operator = (const int_fast64_t & bi);

    BigInt operator + (BigInt bi);
    BigInt operator - (BigInt bi);
    BigInt operator * (BigInt bi);
    BigInt operator / (BigInt bi);
    BigInt operator % (BigInt bi);

    char operator < (BigInt bi);
    char operator > (BigInt bi);
    char operator <= (BigInt bi);
    char operator >= (BigInt bi);
    char operator == (BigInt bi);
    char operator != (BigInt bi);

    int & operator[] (int k);
    int getSize();
    int getSign();

    std::string BigIntToString();
    int_fast64_t BigIntToInt();
};

#endif  // MODULES_BIG_INT_INCLUDE_BIG_INT_H_

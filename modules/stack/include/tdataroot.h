// Copyright 2019 Balynin Alexey

#ifndef MODULES_STACK_INCLUDE_TDATAROOT_H_
#define MODULES_STACK_INCLUDE_TDATAROOT_H_

#include "include/tdatacom.h"

const int DefMemSize = 25;
const int DataEmpty = -101;
const int DataFull = -102;
const int DataNoMem = -103;

typedef int Vector;
typedef Vector* PVector;
typedef int TData;

enum TMemType { MEM_HOLDER, MEM_RENTER };

class TDataRoot: public TDataCom {
 protected:
    PVector pMem;
    int MemSize;
    int DataCount;
    TMemType MemType;
 public:
    virtual ~TDataRoot();
    explicit TDataRoot(int Size = DefMemSize);
    virtual bool IsEmpty(void) const;
    virtual bool IsFull(void) const;
    virtual void Put(const TData &Val) = 0;
    virtual TData Get(void) = 0;
    virtual int IsValid() = 0;
    friend class TMultiStack;
    friend class TSuperMultiStack;
    friend class TComplexMultiStack;
};

#endif  // MODULES_STACK_INCLUDE_TDATAROOT_H_

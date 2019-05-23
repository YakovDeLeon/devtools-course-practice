// Copyright 2019 Balynin Alexey

#ifndef MODULES_STACK_INCLUDE_TSTACK_H_
#define MODULES_STACK_INCLUDE_TSTACK_H_

#include "include/tdataroot.h"

class TStack :public TDataRoot {
 private:
    int top_;
 public:
    explicit TStack(int Size = DefMemSize);
    void Put(const TData &Val);
    TData Get();
    TData TopElem();
    int IsValid();
};

#endif  // MODULES_STACK_INCLUDE_TSTACK_H_

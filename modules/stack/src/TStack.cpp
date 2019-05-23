// Copyright 2019 Balynin Alexey

#include <iostream>

#include "include/TStack.h"

TStack::TStack(int Size):TDataRoot(Size) {
    top_ = 0;
}

void TStack::Put(const TData &Val) {
    if (pMem == NULL) {
        SetRetCode(DataNoMem);
        return;
    }
    if (IsFull()) {
        SetRetCode(DataFull);
        return;
    }
    ++DataCount;
    pMem[top_++] = Val;
}

TData TStack::Get(void) {
    if (pMem == NULL) {
        SetRetCode(DataNoMem);
        throw -1;
    }
    if (IsEmpty()) {
        SetRetCode(DataEmpty);
        throw -1;
    }
    --DataCount;
    return pMem[--top_];
}

TData TStack::TopElem(void) {
    if (pMem == NULL) {
        SetRetCode(DataNoMem);
        throw -1;
    }
    if (IsEmpty()) {
        SetRetCode(DataEmpty);
        throw -1;
    }
    return pMem[top_--];
}

int TStack::IsValid() {
    return GetRetCode();
}

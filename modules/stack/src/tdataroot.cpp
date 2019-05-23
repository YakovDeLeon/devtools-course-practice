  // Copyright 2019 Balynin Alexey

#include "include/tdataroot.h"

#include <stdio.h>

TDataRoot::TDataRoot(int Size):TDataCom() {
    DataCount = 0;
    MemSize = Size;
    if (Size == 0) {
        pMem = NULL;
        MemType = MEM_RENTER;
    } else {
        pMem = new Vector[MemSize];
        MemType = MEM_HOLDER;
    }
}

TDataRoot::~TDataRoot() {
    if (MemType == MEM_HOLDER) {
        delete[] pMem;
    }
    pMem = NULL;
}

bool TDataRoot::IsEmpty(void) const {
    return DataCount == 0;
}

bool TDataRoot::IsFull(void) const {
    return DataCount == MemSize;
}

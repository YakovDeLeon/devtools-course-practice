// Copyright 2019 Gaydaychuk Yury

#ifndef MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_
#define MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_

class QuickSort {
 public:
    bool CheckIncreasing(const int *pArr, const int size);
    void MySort(int *pArr, int size);
 private:
    void MySwap(int* a, int* b);
    int Partition(int *arr, int low, int high);
    void BoundedSort(int *arr, int low, int high);
};

#endif  // MODULES_QUICK_SORT_INCLUDE_QUICK_SORT_H_

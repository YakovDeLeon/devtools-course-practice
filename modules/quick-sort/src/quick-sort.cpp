// Copyright 2019 Gaydaychuk Yury

#include "include/quick-sort.h"

#include <stdbool.h>

bool QuickSort::CheckIncreasing(const int *pArr, const int size) {
    for (int i = 0; i < size - 1; i++) {
        if (pArr[i] > pArr[i + 1]) {
            return false;
        }
    }
    return true;
}

void QuickSort::MySort(int *pArr, int size) {
    BoundedSort(pArr, 0, size - 1);
}

void QuickSort::MySwap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int QuickSort::Partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            MySwap(&arr[i], &arr[j]);
        }
    }
    MySwap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void QuickSort::BoundedSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = Partition(arr, low, high);
        BoundedSort(arr, low, pi - 1);
        BoundedSort(arr, pi + 1, high);
    }
}

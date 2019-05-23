// Copyright 2019 Dudchenko Anton

#include <vector>
#include <iostream>
#include <algorithm>
#include "include/BatcherSort.h"

BatcherSort::BatcherSort(std::vector<int> vec) :v_(vec) {
    if (((v_.size()) & (v_.size() - 1)) != 0 && v_.size() != 0)
        throw -1;
}

BatcherSort::~BatcherSort() {
    v_.clear();
}

void BatcherSort::Shuffle(int l, int r) {
    int i, j;
    int m = (l + r) / 2;
    std::vector<int> tmp(v_.size());

    if (r - l + 1 <= 1)
        return;

    for (j = 0, i = l; i <= m; j += 2, i++)
        tmp[j] = v_[i];

    for (j = 1, i = m + 1; i <= r; j += 2, i++)
        tmp[j] = v_[i];

    for (i = l; i <= r; i++)
        v_[i] = tmp[i - l];

    tmp.clear();
}

void BatcherSort::Compexch(int a, int b) {
    if (v_[b] < v_[a])
        std::swap(v_[a], v_[b]);
}

void BatcherSort::Unshuffle(int l, int r) {
    int i, j;
    int m = (l + r) / 2;
    std::vector<int> tmp(v_.size());

    if (r - l + 1 <= 1)
        return;

    for (j = 0, i = l; i <= r; j++, i += 2)
        tmp[j] = v_[i];

    for (j = m + 1 - l, i = l + 1; i <= r; j++, i += 2)
        tmp[j] = v_[i];

    for (i = l; i <= r; i++)
        v_[i] = tmp[i - l];

    tmp.clear();
}

void BatcherSort::Sort(int l, int r) {
    int m = (l + r) / 2;
    int i;

    if (r - l + 1 == 2) {
        Compexch(l, r);
        return;
    }

    Unshuffle(l, r);
    Sort(l, m);
    Sort(m + 1, r);
    Shuffle(l, r);

    for (i = l; i < r; i++)
        Compexch(i, i + 1);
}

void BatcherSort::BatcherMergeSort(int l, int r) {
    int m = (l + r) / 2;

    if (r - l + 1 <= 1)
        return;

    BatcherMergeSort(l, m);
    BatcherMergeSort(m + 1, r);
    Sort(l, r);
}

int BatcherSort::GetSize() {
    return v_.size();
}

std::vector<int> BatcherSort::GetVec() {
    std::vector<int> tmp = v_;
    return tmp;
}

// Copyright 2019 Dudchenko Anton

#ifndef MODULES_BATCHER_SORT_INCLUDE_BATCHERSORT_H_
#define MODULES_BATCHER_SORT_INCLUDE_BATCHERSORT_H_

#include <vector>

class BatcherSort {
 private:
    std::vector<int> v_;
    void Shuffle(int l, int r);
    void Compexch(int a, int b);
    void Unshuffle(int l, int r);
    void Sort(int l, int r);

 public:
    explicit BatcherSort(std::vector<int> = {});
    ~BatcherSort();
    std::vector<int> GetVec();
    int GetSize();
    void BatcherMergeSort(int l, int r);
};
#endif  // MODULES_BATCHER_SORT_INCLUDE_BATCHERSORT_H_

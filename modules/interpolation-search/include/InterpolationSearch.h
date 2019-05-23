// Copyright 2019 Perov Dima

#ifndef MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATIONSEARCH_H_
#define MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATIONSEARCH_H_

#include<string>

class InterpolationSearch {
 protected:
    int* pointerSortedData;
    unsigned sizeSortedData;
    int64_t findIndex;

 public:
    InterpolationSearch(int* myPointerSortedData, unsigned mySizeSortedData);
    InterpolationSearch();
    ~InterpolationSearch();
    int64_t GetFindIndex();
    unsigned GetSizeData();
    int* GetPointerData();
    void SetSortedData(int* myPointerSortedData, unsigned mySizeSortedData);
    int64_t Search(int toFind, unsigned myLeft = 0, unsigned myRight = 0);
};

#endif  // MODULES_INTERPOLATION_SEARCH_INCLUDE_INTERPOLATIONSEARCH_H_"

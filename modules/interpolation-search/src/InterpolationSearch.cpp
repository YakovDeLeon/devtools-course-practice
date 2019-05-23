// Copyright 2019 Perov Dima

#include "include/InterpolationSearch.h"

InterpolationSearch::InterpolationSearch(int* myPointerSortedData,
unsigned mySizeSortedData) {
    pointerSortedData  = myPointerSortedData;
    sizeSortedData = mySizeSortedData;
}

InterpolationSearch::InterpolationSearch() {
    pointerSortedData = nullptr;
    sizeSortedData  = 0;
}

InterpolationSearch::~InterpolationSearch() {
    pointerSortedData = nullptr;
}

int64_t InterpolationSearch::GetFindIndex() {
    return findIndex;
}

unsigned InterpolationSearch::GetSizeData() {
    return sizeSortedData;
}

int* InterpolationSearch::GetPointerData() {
    return pointerSortedData;
}

void InterpolationSearch::SetSortedData(int* myPointerSortedData,
unsigned mySizeSortedData) {
    pointerSortedData  = myPointerSortedData;
    sizeSortedData = mySizeSortedData;
}

int64_t InterpolationSearch::Search(int toFind, unsigned myLeft,
unsigned myRight) {
    unsigned left = myLeft;

    if (myRight == 0)
        myRight = sizeSortedData - 1;

    unsigned right = myRight;

    while (pointerSortedData[left] < toFind &&
    pointerSortedData[right] > toFind) {
        unsigned mid = left + ((toFind - pointerSortedData[left]) *
        (right - left)) / (pointerSortedData[right] - pointerSortedData[left]);

        if (pointerSortedData[mid] < toFind) {
            left = mid + 1;
        } else if (pointerSortedData[mid] > toFind) {
            right = mid - 1;
        } else {
            findIndex = mid;
            return findIndex;
        }
    }

    if (pointerSortedData[left] == toFind) {
        findIndex = left;
        return findIndex;
    }
    if (pointerSortedData[right] == toFind) {
        findIndex = right;
        return findIndex;
    }

    findIndex = -1;
    return findIndex;  // Not found
}

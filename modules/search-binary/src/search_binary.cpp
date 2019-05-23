// Copyright 2019 Yunin Ivan

#include "include/search_binary.h"

int SearchBinary::Search(const int key, const int *arr, const int size) {
    if (size < 1) return -1;
    int left = 0;
    int right = size - 1;
    while (true) {
        int midd = (left + right) / 2;
        if (key < arr[midd])
            right = midd - 1;
        else if (key > arr[midd])
            left = midd + 1;
        else
            return midd;
        if (left > right)
            return -1;
    }
}

// Copyright 2019 Valiullin Damir

#include "include/radix.h"

#include <string>

Radix::Radix(const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    } else {
        size_ = size;

        counter_ = new int[256];
        offset_ = new int[256];
        temp_array_ = new int[size_];
    }
}

Radix::Radix(int* input_array, const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    } else {
        size_ = size;

        counter_ = new int[256];
        offset_ = new int[256];
        temp_array_ = new int[size];

        SortArray(input_array);
    }
}

Radix::~Radix() {
    delete[] temp_array_;
    delete[] offset_;
    delete[] counter_;
}

void Radix::RadixSort(int* input_array, const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    } else {
        if (size != size_) {
            delete[] temp_array_;

            size_ = size;
            temp_array_ = new int[size_];
        }

        CountingSort(input_array, temp_array_, 0);
        CountingSort(temp_array_, input_array, 1);
        CountingSort(input_array, temp_array_, 2);
        LastCountingSort(temp_array_, input_array);
    }
}

int Radix::GetSize() const {
    return size_;
}

void Radix::SetSize(const int size) {
    if (size <= 0) {
        throw std::string("Size can't be zero or lower");
    } else {
        if (size != size_) {
            delete[] temp_array_;

            size_ = size;
            temp_array_ = new int[size_];
        }
    }
}
int Radix::HowMuchMem() {
    int mem = 0;
    mem += 2 * 256 * 4 + 4;
    mem += size_ * 4;
    return mem;
}

void Radix::ResetCounter() {
    for (int i = 0; i < 256; ++i) {
        counter_[i] = 0;
    }
}

void Radix::SortArray(int* input_array) {
    CountingSort(input_array, temp_array_, 0);
    CountingSort(temp_array_, input_array, 1);
    CountingSort(input_array, temp_array_, 2);
    LastCountingSort(temp_array_, input_array);
}

void Radix::CountingSort(int* input_array, int* output_array, int byte) {
    unsigned char* c = reinterpret_cast<unsigned char*>(input_array);
    offset_[0] = 0;
    ResetCounter();

    for (int i = 0; i < size_; ++i) {
        counter_[c[i * 4 + byte]]++;
    }

    for (int i = 1; i < 256; ++i) {
        offset_[i] = counter_[i - 1] + offset_[i - 1];
    }

    for (int i = 0; i < size_; ++i) {
        output_array[offset_[c[i * 4 + byte]]++] = input_array[i];
    }
}

void Radix::LastCountingSort(int* input_array, int* output_array) {
    char* c = reinterpret_cast<char*>(input_array);
    offset_[0] = 0;
    ResetCounter();

    for (int i = 0; i < size_; ++i) {
        counter_[c[i * 4 + 3] + 128]++;
    }

    for (int i = 1; i < 256; ++i) {
        offset_[i] = counter_[i - 1] + offset_[i - 1];
    }

    for (int i = 0; i < size_; ++i) {
        output_array[offset_[c[i * 4 + 3] + 128]++] = input_array[i];
    }
}

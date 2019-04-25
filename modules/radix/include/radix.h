// Copyright 2019 Valiullin Damir

#ifndef MODULES_RADIX_INCLUDE_RADIX_H_
#define MODULES_RADIX_INCLUDE_RADIX_H_

class Radix {
 public:
    explicit Radix(const int size = 1);
    Radix(int* input_array, const int size);
    ~Radix();

    void RadixSort(int* input_array, const int size);
    int GetSize() const;
    void SetSize(const int size);
    int HowMuchMem();

 private:
    void ResetCounter();
    void SortArray(int* input_array);
    void CountingSort(int* input_array, int* output_array, int byte);
    void LastCountingSort(int* input_array, int* output_array);

    int size_;
    int* temp_array_;
    int* counter_;
    int* offset_;
};

#endif  // MODULES_RADIX_INCLUDE_RADIX_H_

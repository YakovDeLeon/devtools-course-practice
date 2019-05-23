// Copyright 2019 Volkov Pavel

#ifndef MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_
#define MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

#include <string>

class BitArray {
 public:
    BitArray();
    explicit BitArray(const int _bit_count);
    BitArray(const BitArray& _bit_array);

    ~BitArray();

    BitArray& operator= (const BitArray& f_copy);

    int size();


    void SetBit(int bit_number, bool value);

    bool GetBit(int bit_number);

    std::string print_string();

 private:
    int *memory;
    int memory_size;
    int bit_count;
};

#endif  // MODULES_BIT_ARRAY_INCLUDE_BIT_ARRAY_H_

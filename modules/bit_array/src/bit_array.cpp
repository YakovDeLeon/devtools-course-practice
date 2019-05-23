// Copyright 2019 Volkov Pavel

#include "include/bit_array.h"
#include <cstdlib>
#include <iostream>
#include <string>


BitArray::BitArray() {
    bit_count = 256;

    memory_size = bit_count / (8 * sizeof(int));

    memory = new int[memory_size];

    for (int i = 0; i < memory_size; i++) {
        memory[i] = 0;
    }
}

BitArray::BitArray(const int _bit_count) {
    bit_count = _bit_count;

    if (bit_count <= 0)
        throw std::string("Can't create negative and zero array");

    memory_size = bit_count / (8 * sizeof(int));

    if (bit_count % (8 * sizeof(int)) != 0)
        memory_size += 1;

    memory = new int[memory_size];

    for (int i = 0; i < memory_size; i++) {
        memory[i] = 0;
    }
}

BitArray::BitArray(const BitArray& _bit_array) {
    memory_size = _bit_array.memory_size;
    bit_count = _bit_array.bit_count;

    memory = new int[memory_size];

    for (int i = 0; i < memory_size; i++) {
        memory[i] = _bit_array.memory[i];
    }
}

BitArray::~BitArray() {
    delete memory;
    memory = nullptr;
}

int BitArray::size() {
    return bit_count;
}

void BitArray::SetBit(int bit_number, bool value) {
    if (bit_number >= bit_count) {
        throw std::string("Value out of range");
    }

    int choose_byte;
    int choose_bit;

    choose_byte = bit_number / (8 * sizeof(int));
    choose_bit = bit_number % (8 * sizeof(int));

    if (value == true) {
        memory[choose_byte] |= 1 << choose_bit;
    } else {
        memory[choose_byte] &= ~(1 << choose_bit);
    }
}

bool BitArray::GetBit(int bit_number) {
    if (bit_number >= bit_count) {
        throw std::string("Value out of range");
    }

    int choose_byte;
    int choose_bit;

    choose_byte = bit_number / (8 * sizeof(int));
    choose_bit = bit_number % (8 * sizeof(int));

    if ((memory[choose_byte] & (1 << choose_bit)) == 0) {
        return false;
    } else {
        return true;
    }
}

std::string BitArray::print_string() {
    std::string out = "";
    int prented_count = 0;


    for (int i = 0; i < memory_size; i++) {
        int byte = memory[i];
        int mask = 1;

        for (unsigned int j = 0;
             (j < (sizeof(int) * 8)) && (prented_count < bit_count); j++) {
            prented_count += 1;

            bool val = byte & (mask << j);
            if (val) {
                out += "1";
            } else {
                out += "0";
            }
        }
    }
    return out;
}

BitArray& BitArray::operator=(const BitArray& f_copy) {
    delete[] memory;
    memory = nullptr;

    memory_size = f_copy.memory_size;
    bit_count = f_copy.bit_count;

    memory = static_cast<int*>(malloc(memory_size * sizeof(int)));

    for (int i = 0; i < memory_size; i++) {
        memory[i] = f_copy.memory[i];
    }

    return *this;
}





// Copyright 2019 Konnov Sergey

#include <iostream>
#include "include/vigenere_cipher_application.h"

int main(int argc, char const ** argv) {
    VigenereCipherApplication application;
    std::cout << application(argc, argv);
    return 0;
}

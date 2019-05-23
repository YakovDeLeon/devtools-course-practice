// Copyright 2019 Konnov Sergey

#ifndef MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_APPLICATION_H_
#define MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_APPLICATION_H_

#include "include/vigenere_cipher.h"
#include <string>

class VigenereCipherApplication {
 private:
    enum class Operation {
        Encrypt,
        Decrypt
    };
    std::string Help(const char* appname);
    Operation ParseOperation(const char* argv);
    VigenereCipher vchiph_;
    std::string key_;
    std::string operation_;
 public:
    VigenereCipherApplication() = default;
    std::string operator()(int argc, const char ** argv);
};

#endif  // MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_APPLICATION_H_

// Copyright 2019 Repin Vladimir
#ifndef MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_H_
#define MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_H_

#include <string>

class CaesarCipher {
 public:
    static const int letters_num = 26;
    static std::string Encrypt(const std::string& message, const int& key);
    static std::string Decrypt(const std::string& message, const int& key);
 private:
    static std::string Shift(const std::string& message, const int& key);
};

#endif  // MODULES_CAESAR_CIPHER_INCLUDE_CAESAR_CIPHER_H_

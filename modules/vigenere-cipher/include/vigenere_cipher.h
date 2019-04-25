// Copyright 2019 Obolenskiy Arseniy
#ifndef MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
#define MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_
#include <string>

class VigenereCipher {
 private:
    static std::string ExpandKey(const std::string &key, int size);
 public:
    static std::string Encrypt(const std::string &message,
                               const std::string &key);
    static std::string Decrypt(const std::string &message,
                               const std::string &key);
};

#endif  // MODULES_VIGENERE_CIPHER_INCLUDE_VIGENERE_CIPHER_H_

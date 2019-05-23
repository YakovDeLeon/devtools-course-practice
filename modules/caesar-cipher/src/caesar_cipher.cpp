// Copyright 2019 Repin Vladimir
#include <string>

#include "include/caesar_cipher.h"

std::string CaesarCipher::Shift(const std::string& message, const int &key) {
    std::string shifted_message(message);
    int usedkey = key;
    if (usedkey < 0)
        usedkey = letters_num + usedkey;

    for (unsigned int i = 0; i < shifted_message.size(); i++) {
        if (isalpha(shifted_message[i])) {
            if (isupper(shifted_message[i]))
                shifted_message[i] = (shifted_message[i] - 'A' + usedkey)
                % letters_num + 'A';
            else
                shifted_message[i] = (shifted_message[i] - 'a' + usedkey)
                % letters_num + 'a';
        }
    }

    return shifted_message;
}

std::string CaesarCipher::Encrypt(const std::string& message, const int &key) {
        return Shift(message, key % letters_num);
}

std::string CaesarCipher::Decrypt(const std::string &message, const int &key) {
        return Shift(message, (-key) % letters_num);
}

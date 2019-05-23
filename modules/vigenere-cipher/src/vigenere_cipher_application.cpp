// Copyright 2019 Konnov Sergey

#include <cstring>
#include <string>
#include <stdexcept>
#include "include/vigenere_cipher_application.h"

std::string VigenereCipherApplication::Help(const char * appname) {
    return "This is application for Vigenere Cipher Class\n"
        "Usage:\n"
        ">" + std::string(appname) + " actions that described below\n"
        "Actions:\n"
        "encrypt <string> <key> - encrypt string using the Vigenere cipher\n"
        "decrypt <string> <key> - decrypt string using the Vigenere cipher\n";
}

VigenereCipherApplication::Operation
    VigenereCipherApplication::ParseOperation(const char * argv) {
    if (strcmp(argv, "encrypt") == 0) {
        return Operation::Encrypt;
    } else if (strcmp(argv, "decrypt") == 0) {
        return Operation::Decrypt;
    } else {
        throw std::runtime_error("Unknown operation: "
            + std::string(argv));
    }
}

std::string VigenereCipherApplication::operator()
                                (int argc, const char ** argv) {
    if (argc == 1)
        return Help(*argv);
    try {
        Operation oper = ParseOperation(argv[1]);
        if (argc < 4)
            throw std::runtime_error("Too few arguments!\n");
        if (argc > 4)
            throw std::runtime_error("Too many arguments!\n");
        if (oper == Operation::Encrypt) {
            return std::string(vchiph_.Encrypt(argv[2], argv[3]));
        } else {
            return std::string(vchiph_.Decrypt(argv[2], argv[3]));
        }
    }
    catch (std::runtime_error &re) {
        return re.what();
    }
}

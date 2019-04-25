// Copyright 2019 Obolenskiy Arseniy
#include <gtest/gtest.h>
#include <string>
#include "include/vigenere_cipher.h"

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Zero_Shift) {
    // Arrange
    std::string message = "walrus";
    std::string key = "a";

    // Act & Assert
    ASSERT_EQ(message, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Shift_1) {
    // Arrange
    const char shift = 1;
    std::string message = "walrus";
    std::string key = "b";
    std::string expected(message);
    for (unsigned i = 0; i < expected.size(); ++i) {
        int ch = expected[i] + shift;
        if (ch > 122)
            ch -= 26;
        expected[i] = ch;
    }

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Shift_5) {
    // Arrange
    const char shift = 5;
    std::string message = "walrus";
    std::string key = "f";
    std::string expected(message);
    for (unsigned i = 0; i < expected.size(); ++i) {
        int ch = expected[i] + shift;
        if (ch > 122)
            ch -= 26;
        expected[i] = ch;
    }

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Replicate_Caesar_Cipher_With_Shift_25) {
    // Arrange
    const char shift = 25;
    std::string message = "walrus";
    std::string key = "z";
    std::string expected(message);
    for (unsigned i = 0; i < expected.size(); ++i) {
        int ch = expected[i] + shift;
        if (ch > 122)
            ch -= 26;
        expected[i] = ch;
    }

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Throw_An_Exception_With_Incorrect_Key) {
    // Arrange
    std::string message = "word";
    std::string key = "doo1";

    // Act & Assert
    ASSERT_ANY_THROW(VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Can_Encrypt_Word_With_Key_With_The_Same_Size) {
    // Arrange
    std::string message = "word";
    std::string key = "door";
    std::string expected = "zcfu";

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Encrypting_Ignores_Non_Alphabetic_Chars_In_Message) {
    // Arrange
    std::string message = "Vigenere Cipher 123_+=0";
    std::string key = "aba";
    std::string expected = "Vjgeoerf Cjphfr 123_+=0";

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Decrypting_Ignores_Non_Alphabetic_Chars_In_Message) {
    // Arrange
    std::string message = "Vjgeoerf Cjphfr 123_+=0";
    std::string key = "aba";
    std::string expected = "Vigenere Cipher 123_+=0";

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Decrypt(message, key));
}

TEST(VigenereCipherTest, Encrypting_And_Decrypting_Gives_Original_String) {
    // Arrange
    std::string message = "Lorem ipsum";
    std::string key = "test";

    // Act & Assert
    ASSERT_EQ(message, VigenereCipher::Decrypt(
                        VigenereCipher::Encrypt(message, key),
                        key));
}

TEST(VigenereCipherTest, Handles_Empty_Key) {
    // Arrange
    std::string message = "Lorem ipsum";
    std::string key = "";

    // Act & Assert
    ASSERT_EQ(message, VigenereCipher::Decrypt(
                        VigenereCipher::Encrypt(message, key),
                        key));
}

TEST(VigenereCipherTest, Encrypting_Handles_Empty_Messages) {
    // Arrange
    std::string message = "";
    std::string key = "test";
    std::string expected = "";

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest, Decrypting_Handles_Empty_Messages) {
    // Arrange
    std::string message = "";
    std::string key = "test";
    std::string expected = "";

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Decrypt(message, key));
}

TEST(VigenereCipherTest,
                Encrypting_Handles_Empty_Messages_And_Keys_At_The_Same_Time) {
    // Arrange
    std::string message = "";
    std::string key = "";
    std::string expected = "";

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Encrypt(message, key));
}

TEST(VigenereCipherTest,
                Decrypting_Handles_Empty_Messages_And_Keys_At_The_Same_Time) {
    // Arrange
    std::string message = "";
    std::string key = "";
    std::string expected = "";

    // Act & Assert
    ASSERT_EQ(expected, VigenereCipher::Decrypt(message, key));
}

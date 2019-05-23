// Copyright 2019 Repin Vladimir
#include <gtest/gtest.h>
#include <string>

#include "include/caesar_cipher.h"

// Arrange
class CaesarCipherTest : public ::testing::Test {
 public:
    int zero_key = 0;
    int positive_key = 11;
    int negative_key = -13;
    int big_key = 37;
    std::string empty_message = "";
    std::string message = "Development";
    std::string message_positive_encrypt = "Opgpwzaxpye";
    std::string message_negative_encrypt = "Qrirybczrag";
    std::string complex_message = "Development 2019_C++";
    std::string complex_message_positive_encrypt = "Opgpwzaxpye 2019_N++";
    std::string complex_message_negative_encrypt = "Qrirybczrag 2019_P++";
};



TEST_F(CaesarCipherTest, Empty_Message_Encryption_With_Zero_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(empty_message, zero_key));
    EXPECT_EQ(empty_message, CaesarCipher::Encrypt(empty_message, zero_key));
}

TEST_F(CaesarCipherTest,
       Empty_Message_Encryption_With_Positive_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(empty_message, positive_key));
    EXPECT_EQ(empty_message,
              CaesarCipher::Encrypt(empty_message, positive_key));
}

TEST_F(CaesarCipherTest,
       Empty_Message_Encryption_With_Negative_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(empty_message, negative_key));
    EXPECT_EQ(empty_message,
              CaesarCipher::Encrypt(empty_message, negative_key));
}



TEST_F(CaesarCipherTest, Message_Encryption_With_Zero_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(message, zero_key));
    EXPECT_EQ(message, CaesarCipher::Encrypt(message, zero_key));
}

TEST_F(CaesarCipherTest,
       Message_Encryption_With_Positive_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(message, positive_key));
    EXPECT_EQ(message_positive_encrypt,
              CaesarCipher::Encrypt(message, positive_key));
}

TEST_F(CaesarCipherTest,
       Message_Encryption_With_Negative_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(message, negative_key));
    EXPECT_EQ(message_negative_encrypt,
              CaesarCipher::Encrypt(message, negative_key));
}



TEST_F(CaesarCipherTest,
       Complex_Message_Encryption_With_Zero_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(complex_message, zero_key));
    EXPECT_EQ(complex_message,
              CaesarCipher::Encrypt(complex_message, zero_key));
}

TEST_F(CaesarCipherTest,
       Complex_Message_Encryption_With_Positive_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(complex_message, positive_key));
    EXPECT_EQ(complex_message_positive_encrypt,
              CaesarCipher::Encrypt(complex_message, positive_key));
}

TEST_F(CaesarCipherTest,
       Complex_Message_Encryption_With_Negative_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Encrypt(complex_message, negative_key));
    EXPECT_EQ(complex_message_negative_encrypt,
              CaesarCipher::Encrypt(complex_message, negative_key));
}



TEST_F(CaesarCipherTest,
       Empty_Message_Decryption_With_Zero_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(empty_message, zero_key));
    EXPECT_EQ(empty_message,
              CaesarCipher::Decrypt(empty_message, zero_key));
}

TEST_F(CaesarCipherTest,
       Empty_Message_Decryption_With_Positive_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(empty_message, positive_key));
    EXPECT_EQ(empty_message,
              CaesarCipher::Decrypt(empty_message, positive_key));
}

TEST_F(CaesarCipherTest,
       Empty_Message_Decryption_With_Negative_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(empty_message, negative_key));
    EXPECT_EQ(empty_message,
              CaesarCipher::Decrypt(empty_message, negative_key));
}



TEST_F(CaesarCipherTest, Message_Decryption_With_Zero_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(message, zero_key));
    EXPECT_EQ(message, CaesarCipher::Decrypt(message, zero_key));
}

TEST_F(CaesarCipherTest,
       Message_Decryption_With_Positive_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(message, positive_key));
    EXPECT_EQ(message,
              CaesarCipher::Decrypt(message_positive_encrypt, positive_key));
}

TEST_F(CaesarCipherTest,
       Message_Decryption_With_Negative_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(message, negative_key));
    EXPECT_EQ(message,
              CaesarCipher::Decrypt(message_negative_encrypt, negative_key));
}



TEST_F(CaesarCipherTest,
       Complex_Message_Decryption_With_Zero_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(complex_message, zero_key));
    EXPECT_EQ(complex_message,
              CaesarCipher::Decrypt(complex_message, zero_key));
}

TEST_F(CaesarCipherTest,
       Complex_Message_Decryption_With_Positive_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(complex_message, positive_key));
    EXPECT_EQ(complex_message,
              CaesarCipher::Decrypt(complex_message_positive_encrypt,
                                    positive_key));
}

TEST_F(CaesarCipherTest,
       Complex_Message_Decryption_With_Negative_Key_Is_Correct) {
    // Act & Assert
    EXPECT_NO_THROW(CaesarCipher::Decrypt(complex_message, negative_key));
    EXPECT_EQ(complex_message,
              CaesarCipher::Decrypt(complex_message_negative_encrypt,
                                    negative_key));
}



TEST_F(CaesarCipherTest, Big_Key_Encryption_Is_Correct) {
    // Act & Assert
    EXPECT_EQ(message_positive_encrypt,
              CaesarCipher::Encrypt(message, big_key));
}

TEST_F(CaesarCipherTest, Big_Key_Decryption_Is_Correct) {
    // Act & Assert
    EXPECT_EQ(message,
        CaesarCipher::Decrypt(message_positive_encrypt, big_key));
}

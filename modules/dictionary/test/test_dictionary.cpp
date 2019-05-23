// Copyright 2019 Ivan Blagin

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/dictionary.h"

using std::string;

const int32_t sizeWord = 6;
const int nLenght = 10000;

TEST(DictionaryTest,
CanCreateDefaultDictionary) {
    Dictionary dict;
    Word root("root", 0);
    dict.Insert(root);
    ASSERT_EQ(root, dict.GetRoot());
}

TEST(DictionaryTest,
CanInsertWord) {
    Dictionary dict;
    Word root("root", 0);
    dict.Insert(root);
    ASSERT_EQ(root, dict.GetRoot());
}

TEST(DictionaryTest,
    CanFindWord) {
    Dictionary dict;
    Word root("root", 0);
    dict.Insert(root);
    ASSERT_EQ(root, dict.Find("root"));
}

TEST(DictionaryTest,
    CanInsertAndFindALotOfWords) {
    Dictionary dict;
    const int length = 10;
    std::vector<string> arr(length);

    for (size_t i = 0; i < length; i++) {
        arr[i] = GetRandomString(sizeWord);
        dict.Insert(Word(arr[i], i));
    }

    for (size_t i = 0; i < length; i++) {
        ASSERT_EQ(Word(arr[i], i), dict.Find(arr[i]));
    }
}

TEST(DictionaryTest,
    CanRemoveWord) {
    Dictionary dict;
    const int length = 10;
    std::vector<string> arr(length);

    for (size_t i = 0; i < length; i++) {
        arr[i] = GetRandomString(sizeWord);
        dict.Insert(Word(arr[i], i));
    }

    dict.Remove(Word(arr[5], 5));
    EXPECT_EQ(Word(), dict.Find(arr[5]));
}

TEST(DictionaryTest,
    CanRemoveALotOfWords) {
    Dictionary dict;
    const int length = 10;
    std::vector<string> arr(length);

    for (size_t i = 0; i < length; i++) {
        arr[i] = GetRandomString(sizeWord);
        dict.Insert(Word(arr[i], i));
    }

    dict.Remove(Word(arr[5], 5));
    EXPECT_EQ(Word(), dict.Find(arr[5]));

    dict.Remove(Word(arr[1], 1));
    EXPECT_EQ(Word(), dict.Find(arr[1]));

    dict.Remove(Word(arr[3], 3));
    EXPECT_EQ(Word(), dict.Find(arr[3]));

    dict.Remove(Word(arr[9], 9));
    EXPECT_EQ(Word(), dict.Find(arr[9]));
}

TEST(DictionaryTest,
    CanRemoveAlldict) {
    Dictionary dict;
    std::vector<Word> vWords(nLenght);

    for (int32_t i = 0; i < nLenght; i++) {
        vWords.push_back(Word(GetRandomString(sizeWord), i));
        dict.Insert(vWords[i]);
    }

    for (int32_t i = 0; i < nLenght; i++) {
        dict.Remove(vWords[i]);
    }

    EXPECT_EQ(Word(), dict.GetRoot());
}

TEST(DictionaryTest,
    CanInsertWordsAscending) {
    Dictionary dict;

    for (int32_t i = 0; i < nLenght; i++) {
        dict.Insert(Word(std::to_string(i), i));
        EXPECT_EQ(Word(std::to_string(i), i), dict.Find(std::to_string(i)));
    }
}

TEST(DictionaryTest,
    CanInsertWordsDescending) {
    Dictionary dict;

    for (int32_t i = nLenght; i != 0; i--) {
        dict.Insert(Word(std::to_string(i), i));
        EXPECT_EQ(Word(std::to_string(i), i), dict.Find(std::to_string(i)));
    }
}

TEST(DictionaryTest,
    CanInsertWordWithDLRotate) {
    Dictionary dict;

    dict.Insert(Word(std::to_string(4), 4));
    dict.Insert(Word(std::to_string(5), 5));
    dict.Insert(Word(std::to_string(7), 7));
    dict.Insert(Word(std::to_string(9), 9));
    // There is double left rotation will be executed
    dict.Insert(Word(std::to_string(8), 8));
    EXPECT_EQ(Word(std::to_string(8), 8), dict.Find(std::to_string(8)));
}

TEST(DictionaryTest,
    CanInsertWordWithDRRotate) {
    Dictionary dict;

    dict.Insert(Word(std::to_string(5), 5));
    dict.Insert(Word(std::to_string(6), 6));
    dict.Insert(Word(std::to_string(3), 3));
    dict.Insert(Word(std::to_string(1), 1));
    // There is double tight rotation will be executed
    dict.Insert(Word(std::to_string(2), 2));
    EXPECT_EQ(Word(std::to_string(2), 2), dict.Find(std::to_string(2)));
}

TEST(DictionaryTest,
    CanRemoveWordsAscending) {
    Dictionary dict;

    for (int32_t i = 0; i != nLenght; i++) {
        dict.Insert(Word(std::to_string(i), i));
    }

    for (int32_t i = 0; i != nLenght; i++) {
        dict.Remove(Word(std::to_string(i), i));
        EXPECT_EQ(Word(), dict.Find(std::to_string(i)));
    }
}

TEST(DictionaryTest,
    CanRemoveWordsDescending) {
    Dictionary dict;

    for (int32_t i = 0; i != nLenght; i++) {
        dict.Insert(Word(std::to_string(i), i));
    }

    for (int32_t i = nLenght; i != 0; i--) {
        dict.Remove(Word(std::to_string(i), i));
        EXPECT_EQ(Word(), dict.Find(std::to_string(i)));
    }
}

TEST(DictionaryTest,
    CanRemoveRoot) {
    Dictionary dict;

    for (int32_t i = 0; i != nLenght; i++) {
        dict.Insert(Word(std::to_string(i), i));
    }

    Word nRoot = dict.GetRoot();
    dict.Remove(nRoot);
    EXPECT_EQ(Word(), dict.Find(nRoot.first));
}

TEST(DictionaryTest,
    CanRemoveNonexistRoot) {
    Dictionary dict;
    dict.Insert(Word(std::to_string(0), 0));
    dict.Remove(Word(std::to_string(0), 0));
    EXPECT_EQ(Word(), dict.Find("Poebasfaaluepldsas"));
}

TEST(DictionaryTest,
    CanRemoveNonexistWord) {
    Dictionary dict;

    for (int32_t i = 0; i != nLenght; i++) {
        dict.Insert(Word(std::to_string(i), i));
    }

    Word nRoot = dict.GetRoot();
    dict.Remove(Word("-1", 1));
    for (int32_t i = 0; i != nLenght; i++) {
        EXPECT_EQ(Word(std::to_string(i), i), dict.Find(std::to_string(i)));
    }
    EXPECT_EQ(Word(), dict.Find("Poebasfaaluepldsas"));
}

TEST(DictionaryTest,
    CanAddExistWord) {
    Dictionary dict;
    dict.Insert(Word(std::to_string(0), 0));

    for (int32_t i = 1; i != nLenght; i++) {
        dict.Insert(Word(std::to_string(0), 0));
        EXPECT_EQ(Word(std::to_string(0), 0), dict.Find(std::to_string(0)));
        EXPECT_EQ(Word(), dict.Find(std::to_string(i)));
    }
}

TEST(DictionaryTest,
    CanChangeValExistWord) {
    Dictionary dict;
    dict.Insert(Word(std::to_string(0), 0));
    dict.Insert(Word(std::to_string(0), 2));
    EXPECT_EQ(Word("0", 2), dict.Find("0"));
}

TEST(DictionaryTest,
    CanFoundMaxElement) {
    Dictionary dict;
    for (char i = 0; i != INT8_MAX; i++) {
        dict.Insert(Word(std::string(1, i), i));
    }
    EXPECT_EQ(Word(std::string(1, INT8_MAX-1), INT8_MAX - 1), dict.FindMax());
}

TEST(DictionaryTest,
    CanFoundMinElement) {
    Dictionary dict;
    for (char i = 0; i != INT8_MAX; i++) {
        dict.Insert(Word(std::string(1, i), i));
    }
    EXPECT_EQ(Word(std::string(1, 0), 0), dict.FindMin());
}

// Copyright 2019 Alexander Batashev

#ifndef MODULES_SET_INCLUDE_SET_H_
#define MODULES_SET_INCLUDE_SET_H_

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <vector>

template<typename T>
class Set {
 private:
    std::vector<T> items_;

 public:
    using const_iterator = typename std::vector<T>::const_iterator;

    Set() = default;
    Set(const Set &src) = default;
    Set& operator=(const Set &src) = default;
    ~Set() = default;

    explicit Set(const std::vector<T> vector) : items_(std::move(vector)) {
        std::sort(items_.begin(), items_.end());
        items_.erase(std::unique(items_.begin(), items_.end()), items_.end());
    }

    Set(const std::initializer_list<T> list) : items_(std::move(list)) {
        std::sort(items_.begin(), items_.end());
        items_.erase(std::unique(items_.begin(), items_.end()), items_.end());
    }

    const_iterator begin() const { return items_.begin(); }

    const_iterator end() const { return items_.end(); }

    size_t size() const { return items_.size(); }

    void Add(T item) {
        if (std::find(items_.begin(), items_.end(), item) == items_.end()) {
            items_.push_back(item);
            std::sort(items_.begin(), items_.end());
        }
    }

    void Remove(const T &item) {
        const auto &pos = std::find(items_.begin(), items_.end(), item);
        if (pos != items_.end()) {
            items_.erase(pos);
        }
    }

    bool Contains(const T &item) const {
        for (const auto &other : items_) {
            if (item == other) {
                return true;
            }
        }

        return false;
    }

    static Set Union(const Set &set1, const Set &set2) {
        Set<T> resSet(set1);

        for (auto item : set2) {
            resSet.Add(item);
        }

        return resSet;
    }

    static Set Intersection(const Set &set1, const Set &set2) {
        Set<T> resSet(set1);

        for (auto item : set1) {
            if (!set2.Contains(item)) {
                resSet.Remove(item);
            }
        }

        return resSet;
    }

    static Set Difference(const Set &set1, const Set &set2) {
        Set<T> resSet(set1);

        for (auto item : set2) {
            resSet.Remove(item);
        }

        return resSet;
    }

    static Set SymmetricDifference(const Set &set1, const Set &set2) {
        return Difference(Union(set1, set2), Intersection(set1, set2));
    }

    bool IsSubset(const Set &other) const {
        for (auto item : other) {
            if (!Contains(item)) {
                return false;
            }
        }

        return true;
    }

    bool operator==(const Set &other) const {
        return this->items_ == other.items_;
    }

    bool operator!=(const Set &other) const {
        return this->items_ != other.items_;
    }
};

#endif  // MODULES_SET_INCLUDE_SET_H_

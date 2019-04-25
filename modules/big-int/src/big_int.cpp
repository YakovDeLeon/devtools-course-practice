// Copyright 2019 Muravev Denis

#include <string>
#include "include/big_int.h"

BigInt::BigInt(int_fast64_t bi, int _size_mem) {
    size = 1;
    sign = 1;

    if (bi == 0) {
        size_mem = _size_mem;
        mem = new int[size_mem];
        for (int i = 0; i < size_mem; i++)
            mem[i] = 0;
    } else {
        if (bi < 0)
            sign = -1;

        if ((bi >= NSB) || (bi <= (-1) * NSB)) {
            size++;
            if ((bi >= (static_cast<int_fast64_t>(NSB) * NSB)) ||
                (bi <= (static_cast<int_fast64_t>(NSB) * NSB * (-1))))
                size++;
        }

        size_mem = size;
        mem = new int[size_mem];
        mem[0] = bi % NSB * sign;
        if (size == 2)
            mem[1] = bi / NSB * sign;
        if (size == 3) {
            int_fast64_t tmp = bi / NSB * sign;
            mem[1] = tmp % NSB;
            mem[2] = tmp / NSB;
        }
    }
}

BigInt::BigInt(const BigInt & bi) {
    size = bi.size;
    size_mem = bi.size_mem;
    sign = bi.sign;
    mem = new int[size_mem];
    for (int i = 0; i < size_mem; i++)
        mem[i] = bi.mem[i];
}

BigInt::BigInt(const std::string & st) {
    std::string str = st;
    size_mem = str.length();
    sign = 1;
    if (str[0] == '-') {
        sign = -1;
        size_mem--;
        str.erase(0, 1);
    }

    int size_numb = size_mem;
    size_mem = (size_mem / 9);
    if (size_numb % 9 != 0)
        size_mem++;
    size = size_mem;
    mem = new int[size_mem];

    for (int i = 0; (i < size - 1) ||
        ((i < size) && (size_numb % 9 == 0)); i++) {
        mem[i] = 0;
        for (int j = 9; j > 0; j--)
            mem[i] = 10 * mem[i] + (str[size_numb - i * 9 - j] - '0');
    }

    if (size_numb % 9 != 0) {
        mem[size - 1] = 0;
        for (int i = 0; i < size_numb % 9; i++)
            mem[size - 1] = 10 * mem[size - 1] + (str[i] - '0');
    }
}

BigInt::~BigInt() {
    delete[] mem;
}

BigInt & BigInt::operator = (const BigInt & bi) {
    if (size_mem != bi.size_mem) {
        if (size_mem != 0)
            delete[] mem;
        size_mem = bi.size_mem;
        mem = new int[size_mem];
    }
    size = bi.size;
    sign = bi.sign;
    for (int i = 0; i < size_mem; i++)
        mem[i] = bi.mem[i];
    return *this;
}

BigInt & BigInt::operator = (const int_fast64_t & bi) {
    if (size_mem != 0)
        delete[] mem;
    size = 1;
    sign = 1;

    if (bi < 0) {
        sign = -1;
    }

    if ((bi >= NSB) || (bi <= (-1) * NSB)) {
        size++;
        if ((bi >=(static_cast<int_fast64_t>(NSB) * NSB))
            || (bi <= (static_cast<int_fast64_t>(NSB) * NSB * (-1))))
            size++;
    }

    size_mem = size;
    mem = new int[size_mem];
    mem[0] = bi % NSB * sign;
    if (size == 2)
        mem[1] = bi / NSB * sign;
    if (size == 3) {
        int_fast64_t tmp = bi / NSB * sign;
        mem[1] = tmp % NSB;
        mem[2] = tmp / NSB;
    }
    return *this;
}

char BigInt::operator < (BigInt bi) {
    if (sign * bi.sign == -1) {
        if (sign == -1) {
            return 1;
        } else {
            return 0;
        }
    }
    if ((sign == -1) && (bi.sign == -1)) {
        sign = 1;
        bi.sign = 1;
        int res = (*this) > bi;
        sign = -1;
        bi.sign = -1;
        return res;
    }
    if (size < bi.size)
        return 1;
    if (size > bi.size)
        return 0;
    for (int i = size - 1; i >= 0; i--)
        if (mem[i] != bi.mem[i]) {
            if (mem[i] < bi.mem[i]) {
                return 1;
            } else {
                return 0;
            }
        }
     return 0;
}

char BigInt::operator > (BigInt bi) {
    if (sign * bi.sign == -1) {
        if (sign == -1) {
            return 0;
        } else {
            return 1;
        }
    }
    if ((sign == -1) && (bi.sign == -1)) {
        sign = 1;
        bi.sign = 1;
        int res = (*this) < bi;
        sign = -1;
        bi.sign = -1;
        return res;
    }
    if (size > bi.size)
        return 1;
    if (size < bi.size)
        return 0;
    for (int i = size - 1; i >= 0; i--)
        if (mem[i] != bi.mem[i]) {
            if (mem[i] > bi.mem[i]) {
                return 1;
            } else {
                return 0;
            }
        }
    return 0;
}

char BigInt::operator <= (BigInt bi) {
    if (sign * bi.sign == -1) {
        if (sign == -1) {
            return 1;
        } else {
            return 0;
        }
    }
    if ((sign == -1) && (bi.sign == -1)) {
        sign = 1;
        bi.sign = 1;
        int res = (*this) >= bi;
        sign = -1;
        bi.sign = -1;
        return res;
    }
    if (size < bi.size)
        return 1;
    if (size > bi.size)
        return 0;
    for (int i = size - 1; i >= 0; i--)
        if (mem[i] != bi.mem[i]) {
            if (mem[i] < bi.mem[i]) {
                return 1;
            } else {
                return 0;
            }
        }
    return 1;
}

char BigInt::operator >= (BigInt bi) {
    if (sign * bi.sign == -1) {
        if (sign == -1) {
            return 0;
        } else {
            return 1;
        }
    }
    if ((sign == -1) && (bi.sign == -1)) {
        sign = 1;
        bi.sign = 1;
        int res = (*this) <= bi;
        sign = -1;
        bi.sign = -1;
        return res;
    }
    if (size > bi.size)
        return 1;
    if (size < bi.size)
        return 0;
    for (int i = size - 1; i >= 0; i--)
        if (mem[i] != bi.mem[i]) {
            if (mem[i] > bi.mem[i]) {
                return 1;
            } else {
                return 0;
            }
        }
    return 1;
}

char BigInt::operator == (BigInt bi) {
    if (sign * bi.sign == -1)
        return 0;
    if (size != bi.size)
        return 0;
    for (int i = size - 1; i >= 0; i--)
        if (mem[i] != bi.mem[i])
            return 0;
    return 1;
}

char BigInt::operator != (BigInt bi) {
    if (sign * bi.sign == -1)
        return 1;
    if (size != bi.size)
        return 1;
    for (int i = size - 1; i >= 0; i--)
        if (mem[i] != bi.mem[i])
            return 1;
    return 0;
}

int & BigInt::operator[] (int k) {
    return mem[k];
}

int BigInt::getSize() {
    return size;
}

int BigInt::getSign() {
    return sign;
}

int BigInt::realSize() {
    int len = 0;
    for (int i = size - 1; i >= 0; i--)
        if (mem[i] != 0) {
            len = i + 1;
            break;
        }
    return len;
}

void BigInt::removingZeros() {
    int len = this->realSize();
    if (len == 0)
        len = 1;
    size_mem = len;
    size = len;

    int* tmp_mem = new int[size_mem];
    for (int i = 0; i < size_mem; i++)
        tmp_mem[i] = mem[i];
    delete[] mem;
    mem = tmp_mem;
}

std::string BigInt::BigIntToString() {
    std::string st = "";
    if ((size == 1) && (mem[0] == 0))
        return "0";

    int tmp;
    for (int i = 0; i < size - 1; i++) {
        tmp = mem[i];
        for (int j = 0; j < 9; j++) {
            st = static_cast<char>((tmp % 10) + '0') + st;
            tmp /= 10;
        }
    }

    tmp = mem[size - 1];
    while (tmp > 0) {
        st = static_cast<char>((tmp % 10) + '0') + st;
        tmp /= 10;
    }

    if (sign == -1)
        st = '-' + st;
    return st;
}

int_fast64_t BigInt::BigIntToInt() {
    int_fast64_t res = 0;
    for (int i = size - 1; i >= 0; i--)
        res = res * NSB + mem[i];
    res *= sign;
    return res;
}

BigInt BigInt::operator + (BigInt bi) {
    if (size < bi.size)
        return bi + (*this);
    BigInt res(0, size + 1);

    if ((sign > 0) && (bi.sign < 0)) {
        bi.sign = 1;
        res = (*this) - bi;
        bi.sign = -1;
        return res;
    }

    if ((sign < 0) && (bi.sign > 0)) {
        sign = 1;
        res = bi - (*this);
        sign = -1;
        return res;
    }

    if ((sign < 0) && (bi.sign < 0))
        res.sign = -1;

    for (int i = 0; i < bi.size; i++) {
        res.mem[i] += (mem[i] + bi.mem[i]);
        res.mem[i + 1] += (res.mem[i] / NSB);
        res.mem[i] %= NSB;
    }

    for (int i = bi.size; i < size; i++) {
        res.mem[i] += mem[i];
        res.mem[i + 1] = (res.mem[i] / NSB);
        res.mem[i] %= NSB;
    }

    res.size = size + 1;
    res.removingZeros();
    return res;
}

BigInt BigInt::operator - (BigInt bi) {
    BigInt res;
    if ((sign > 0) && (bi.sign < 0)) {
        bi.sign = 1;
        res = (*this) + bi;
        bi.sign = -1;
        return res;
    }

    if ((sign < 0) && (bi.sign > 0)) {
        sign = 1;
        res = (*this) + bi;
        sign = -1;
        res.sign = -1;
        return res;
    }

    if ((sign < 0) && (bi.sign < 0)) {
        bi.sign = 1;
        sign = 1;
        res = (*this) - bi;
        res.sign = -1;
        bi.sign = -1;
        sign = -1;
        return res;
    }

    if ((*this) < bi) {
        res = bi - (*this);
        res.sign = -1;
        return res;
    }

    res = *this;
    for (int i = 0; i < bi.size; i++) {
        res.mem[i] -= bi.mem[i];
        if (res.mem[i] < 0) {
            res.mem[i + 1]--;
            res.mem[i] += NSB;
        }
    }

    for (int i = bi.size; i < (size - 1); i++)
        if (res.mem[i] < 0) {
            res.mem[i + 1]--;
            res.mem[i] += NSB;
        }
    res.removingZeros();
    return res;
}

BigInt BigInt::operator * (BigInt bi) {
    int len = size + bi.size + 1;
    BigInt res(0, len);
    res.sign = sign * bi.sign;

    uint_fast64_t tmp;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < bi.size; j++) {
            tmp = res.mem[i + j] +
                (static_cast<uint_fast64_t>(mem[i]) * bi.mem[j]);
            res.mem[i + j + 1] += tmp / NSB;
            res.mem[i + j] = tmp % NSB;
        }
    res.size = len;
    res.removingZeros();
    return res;
}

BigInt BigInt::operator / (BigInt bi) {
    int sg1 = sign, sg2 = bi.sign;
    sign = 1;
    bi.sign = 1;

    BigInt zero(0);
    if (bi == zero) {
        throw std::string("Can't divide by zero");
    }

    if ((*this) < bi) {
        BigInt r(0);
        return r;
    }

    int k = size - bi.size;
    BigInt tmp(0, size), res(0, k + 1);
    BigInt tmp_(0, size + 1), _b(0, size), tmp_b(0, size + 1);
    tmp.size = size;
    res.size = k + 1;
    _b.size = size;
    tmp_b.size = size;

    for (int i = k; i < size; i++)
        tmp.mem[i] = bi.mem[i - k];
    uint_fast64_t l, r, c, p;
    while (1) {
        l = 0;
        r = NSB - 1;
        while (l <= r) {
            c = (l + r) / 2;
            for (int i = k; i <= size; i++) {
                tmp_b.mem[i] = 0;
                tmp_.mem[i] = 0;
            }

            tmp_b.size = size;
            for (int i = 0; i < size - k; i++) {
                p = tmp_.mem[i + k] +
                    (static_cast<uint_fast64_t>(tmp.mem[i + k]) * c);
                tmp_.mem[i + k + 1] += p / NSB;
                tmp_.mem[i + k] = p % NSB;
            }

            for (int i = k; i < size; i++) {
                p = tmp_b.mem[i] +
                    (static_cast<uint_fast64_t>(tmp_.mem[i]) + _b.mem[i]);
                tmp_b.mem[i + 1] = p / NSB;
                tmp_b.mem[i] = p % NSB;
            }
            tmp_b.mem[size] += tmp_.mem[size];

            if (tmp_b.mem[size] != 0)
                tmp_b.size++;

            if (tmp_b >(*this))
                r = c - 1;
            else
                l = c + 1;
        }
        for (int i = k; i <= size; i++) {
            tmp_b.mem[i] = 0;
            tmp_.mem[i] = 0;
        }

        for (int i = 0; i < size - k; i++) {
            p = tmp_.mem[i + k] +
                (static_cast<uint_fast64_t>(tmp.mem[i + k]) * r);
            tmp_.mem[i + k + 1] += p / NSB;
            tmp_.mem[i + k] = p % NSB;
        }

        for (int i = k; i < size; i++) {
            p = tmp_b.mem[i] +
                (static_cast<uint_fast64_t>(tmp_.mem[i]) + _b.mem[i]);
            tmp_b.mem[i + 1] = p / NSB;
            tmp_b.mem[i] = p % NSB;
        }

        tmp_b.mem[size] += tmp_.mem[size];
        for (int i = k; i < size; i++)
            _b.mem[i] = tmp_b.mem[i];
        res.mem[k] = r;
        k--;
        if (k < 0)
            break;
        for (int i = k; i < tmp.size; i++)
            tmp.mem[i] = tmp.mem[i + 1];
        tmp.mem[bi.size + k] = 0;
        tmp.size--;
    }
    res.removingZeros();
    sign = sg1;
    bi.sign = sg2;
    res.sign = sign * bi.sign;
    return res;
}

BigInt BigInt::operator % (BigInt bi) {
    BigInt res;
    res = (*this) / bi;
    res = res * bi;
    return (*this) - res;
}

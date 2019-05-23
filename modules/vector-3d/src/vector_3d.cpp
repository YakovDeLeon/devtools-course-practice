// Copyright 2019 Tolstikov Maksim

#include "include/vector_3d.h"

#include <stdbool.h>
#include <string>
#include <limits>
#include <cmath>

Vector3d::Vector3d() : x(0), y(0), z(0) {}

Vector3d::Vector3d(const double x_,
    const double y_,
    const double z_)
    : x(x_), y(y_), z(z_) {}

Vector3d::Vector3d(const Vector3d& v)
    : x(v.getX()), y(v.getY()), z(v.getZ()) {}

Vector3d& Vector3d::operator = (const Vector3d& v) {
    this->setX(v.getX());
    this->setY(v.getY());
    this->setZ(v.getZ());

    return *this;
}

double Vector3d::getX() const {
    return x;
}

double Vector3d::getY() const {
    return y;
}

double Vector3d::getZ() const {
    return z;
}

void Vector3d::setX(const double x_) {
    x = x_;
}

void Vector3d::setY(const double y_) {
    y = y_;
}

void Vector3d::setZ(const double z_) {
    z = z_;
}

Vector3d Vector3d::operator + (const Vector3d& v) const {
    Vector3d sum;

    sum.setX(this->getX() + v.getX());
    sum.setY(this->getY() + v.getY());
    sum.setZ(this->getZ() + v.getZ());

    return sum;
}

Vector3d Vector3d::operator - (const Vector3d& v) const {
    Vector3d difference;

    difference.setX(this->getX() - v.getX());
    difference.setY(this->getY() - v.getY());
    difference.setZ(this->getZ() - v.getZ());

    return difference;
}

Vector3d Vector3d::operator * (const double& d) const {
    Vector3d multiplication;

    multiplication.setX(this->getX() * d);
    multiplication.setY(this->getY() * d);
    multiplication.setZ(this->getZ() * d);

    return multiplication;
}

Vector3d Vector3d::operator / (const double& d) const {
    Vector3d division;

    if (d == 0.0) {
        throw std::string("Can't divide by zero");
    } else {
        division.setX(this->getX() / d);
        division.setY(this->getY() / d);
        division.setZ(this->getZ() / d);
    }
    return division;
}

double Vector3d::operator * (const Vector3d& v) const {
    return this->getX() * v.getX()
        + this->getY() * v.getY()
        + this->getZ() * v.getZ();
}

Vector3d Vector3d::Cross(const Vector3d& v) const {
    Vector3d multiplication_v;

    multiplication_v.setX(this->getY() * v.getZ() - this->getZ() * v.getY());
    multiplication_v.setY(this->getZ() * v.getX() - this->getX() * v.getZ());
    multiplication_v.setZ(this->getX() * v.getY() - this->getY() * v.getX());

    return multiplication_v;
}

double Vector3d::Norma() const {
    return sqrt(*this * *this);
}

Vector3d Vector3d::Normalize() const {
    Vector3d normal;
    double norm = this->Norma();

    if (norm > 0) {
        normal.setX(this->getX() / norm);
        normal.setY(this->getY() / norm);
        normal.setZ(this->getZ() / norm);
    } else {
        throw std::string("Can't find norma");
    }

    return normal;
}

bool Vector3d::operator == (const Vector3d& v) const {
    if ((this->getX() == v.getX()) &&
        (this->getY() == v.getY()) &&
        (this->getZ() == v.getZ())) {
        return true;
    } else {
        return false;
    }
}

bool Vector3d::operator != (const Vector3d& v) const {
    return !(*this == v);
}


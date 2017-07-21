//
// Created by zakrent on 7/21/17.
//

#include <cmath>
#include "Vector2D.h"

Vector2D::Vector2D(long double x, long double y) : x(x), y(y) {}

Vector2D::~Vector2D() {}

void Vector2D::normalize() {
    long double length = (long double)(sqrt(pow(x, 2)+pow(y, 2)));
    x /= length;
    y /= length;
}

Vector2D Vector2D::operator+(Vector2D SecVector) {
    return Vector2D(this->x + SecVector.x, this->y + SecVector.y);
}

Vector2D Vector2D::operator-(Vector2D SecVector) {
    return Vector2D(this->x - SecVector.x, this->y - SecVector.y);
}

Vector2D Vector2D::operator*(long double mul) {
    return Vector2D(this->x*mul, this->y*mul);
}

void Vector2D::operator+=(Vector2D SecVector) {
    this->x += SecVector.x;
    this->y += SecVector.y;
}

void Vector2D::operator-=(Vector2D SecVector) {
    this->x -= SecVector.x;
    this->y -= SecVector.y;
}

void Vector2D::operator*=(long double mul) {
    this->x *= mul;
    this->y *= mul;
}

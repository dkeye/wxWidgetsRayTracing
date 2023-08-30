#include "Vector3d.h"

#include <cmath>

Vector3d::Vector3d(double x, double y, double z) : x(x), y(y), z(z) {}

double Vector3d::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3d Vector3d::normalized() const {
    double len = length();
    if (len != 0.0) {
        return Vector3d(x / len, y / len, z / len);
    } else {
        return Vector3d(0, 0, 0);
    }
}

Vector3d Vector3d::operator+(const Vector3d& other) const {
    return Vector3d(x + other.x, y + other.y, z + other.z);
}

Vector3d Vector3d::operator-(const Vector3d& other) const {
    return Vector3d(x - other.x, y - other.y, z - other.z);
}

double Vector3d::operator*(const Vector3d& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3d Vector3d::operator*(double scalar) const {
    return Vector3d(x * scalar, y * scalar, z * scalar);
}

Vector3d Vector3d::operator^(const Vector3d& other) const {
    return Vector3d(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

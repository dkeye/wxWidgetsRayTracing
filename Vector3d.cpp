#include "Vector3d.h"

#include <cmath>

Vector3d::Vector3d(float x, float y, float z) : x(x), y(y), z(z) {}

float Vector3d::length() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vector3d Vector3d::normalized() const {
    float len = length();
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

float Vector3d::operator*(const Vector3d& other) const {
    return x * other.x + y * other.y + z * other.z;
}

Vector3d Vector3d::operator*(float scalar) const {
    return Vector3d(x * scalar, y * scalar, z * scalar);
}

Vector3d Vector3d::operator^(const Vector3d& other) const {
    return Vector3d(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

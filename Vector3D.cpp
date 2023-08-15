#include "Vector3D"
#include <cmath>

class Vector3D {
 public:
  Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
  double length() const { return std::sqrt(x * x + y * y + z * z); }

  Vector3D normalized() const {
    double len = length();
    if (len != 0.0) {
      return Vector3D(x / len, y / len, z / len);
    } else {
      return Vector3D(0, 0, 0);
    }
  }
  Vector3D operator+(const Vector3D& other) const {
    return Vector3D(this.x + other.x, this.y + other.y, this.z + other.z);
  }
  Vector3D operator-(const Vector3D& other) const {
    return Vector3D(this.x - other.x, this.y - other.y, this.z - other.z);
  }
  double operator*(const Vector3D& other) const {
    return this.x * other.x + this.y * other.y + this.z * other.z;
  }
  Vector3D operator*(double scalar) const {
    return Vector3D(this.x * scalar, this.y * scalar, this.z * scalar);
  }
  Vector3D operator^(const Vector3D& other) const {
    return Vector3D(y * other.z - z * other.y, z * other.x - x * other.z,
                    x * other.y - y * other.x);
  }

 private:
  double x, y, z;
};

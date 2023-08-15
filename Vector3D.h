#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
 public:
  Vector3D(double x, double y, double z);
  double length() const;
  Vector3D normalized() const;
  // сложение векторов
  Vector3D operator+(const Vector3D& other) const;
  // вычитание векторов
  Vector3D operator-(const Vector3D& other) const;
  // скалярное произведение
  double operator*(const Vector3D& other) const;
  Vector3D operator*(double scalar) const;
  // векторное произведение
  Vector3D operator^(const Vector3D& other) const;

 private:
  double x, y, z;
}

#endif  // VECTOR3D_H

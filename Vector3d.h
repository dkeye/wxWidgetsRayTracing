#pragma once

class Vector3d {
 public:
  Vector3d(double x, double y, double z);
  double length() const;
  Vector3d normalized() const;
  // сложение векторов
  Vector3d operator+(const Vector3d &other) const;
  // вычитание векторов
  Vector3d operator-(const Vector3d &other) const;
  // скалярное произведение
  double operator*(const Vector3d &other) const;
  Vector3d operator*(double scalar) const;
  // векторное произведение
  Vector3d operator^(const Vector3d &other) const;

  double x, y, z;
};

#pragma once

class Vector3d {
 public:
  Vector3d(float x, float y, float z);
  float length() const;
  Vector3d normalized() const;
  // сложение векторов
  Vector3d operator+(const Vector3d &other) const;
  // вычитание векторов
  Vector3d operator-(const Vector3d &other) const;
  // скалярное произведение
  float operator*(const Vector3d &other) const;
  Vector3d operator*(float scalar) const;
  // векторное произведение
  Vector3d operator^(const Vector3d &other) const;

  float x, y, z;
};

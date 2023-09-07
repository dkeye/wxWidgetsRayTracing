#pragma once

#include "Vector3d.h"

class Camera : Vector3d {
 public:
  Camera(float x, float y, float z, float w = 1);

  void multPointMatrix(const Vector3d &point, Vector3d &out);

  void moveView(float x, float y, float z, float w = 1);
  Vector3d operator-(const Vector3d &other) const;

 private:
  float matrix44d[4][4];
};

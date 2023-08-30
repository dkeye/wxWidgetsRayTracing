#pragma once

#include "Vector3d.h"

class Camera : Vector3d {
 public:
  Camera(double x, double y, double z, double w = 1);

  void multPointMatrix(const Vector3d &point, Vector3d &out);

  void moveView(double x, double y, double z, double w = 1);
  Vector3d operator-(const Vector3d &other) const;

 private:
  double matrix44d[4][4];
};

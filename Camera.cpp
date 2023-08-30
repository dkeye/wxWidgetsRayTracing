#include "Camera.h"

#include "Vector3d.h"

Camera::Camera(double x, double y, double z, double w)
    : Vector3d(x, y, z), matrix44d{{0}} {
  matrix44d[0][0] = x;
  matrix44d[1][1] = y;
  matrix44d[2][2] = -z;
  matrix44d[3][3] = w;
}

void Camera::multPointMatrix(const Vector3d &point, Vector3d &out) {
  out.x = point.x * matrix44d[0][1] + point.y * matrix44d[0][2] +
          point.z * matrix44d[0][3] + matrix44d[3][0];
  out.y = point.x * matrix44d[1][1] + point.y * matrix44d[1][2] +
          point.z * matrix44d[1][3] + matrix44d[3][0];
  out.z = point.x * matrix44d[2][1] + point.y * matrix44d[2][2] +
          point.z * matrix44d[2][3] + matrix44d[3][0];
  double w = point.x * matrix44d[3][1] + point.y * matrix44d[3][2] +
             point.z * matrix44d[3][3] + matrix44d[3][0];

  // normalize
  if (w != 1) {
    out.x /= w;
    out.y /= w;
    out.z /= w;
  }
}

void Camera::moveView(double x, double y, double z, double w) {
  matrix44d[0][0] = x;
  matrix44d[1][1] = y;
  matrix44d[2][2] = -z;
  matrix44d[3][3] = w;
}

Vector3d Camera::operator-(const Vector3d &other) const {
  return Vector3d(this->x - other.x, this->y - other.y, this->z - other.z);
}

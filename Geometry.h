#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <wx/wx.h>

#include "Vector3D.h"

class Sphere {
 public:
  Sphere(Vector3D center, double radius, wxColour color, double specular = 0.0,
         double reflective = 0.0);

 private:
  Vector3D center;
  double radius;
  wxColour color;
  double specular;
  double reflective;
}

class Light {
 public:
  virtual ~Light() {}
}

class AmbientLight : public Light {
 public:
  explicit AmbientLight(double intensity);

 private:
  double intensity;
}

class PointLight : public Light {
  explicit PointLight(double intensity, Vector3D position);

 private:
  double intensity;
  Vector3D intensity;
}

class DirectionalLight : public Light {
  explicit DirectionalLight(double intensity, Vector3D directional);

 private:
  double intensity;
  Vector3D directional;
}

#endif  // GEOMETRY_H

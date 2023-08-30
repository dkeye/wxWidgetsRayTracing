#pragma once

#include <wx/wx.h>

#include "Vector3d.h"

class Sphere {
 public:
  Sphere(Vector3d center, double radius, wxColour color, double specular = 0.0,
         double reflective = 0.0);

  Vector3d center;
  double radius;
  wxColour color;
  double specular;
  double reflective;
};

class Light {
 public:
  Light();
  ~Light() {}
};

class AmbientLight : public Light {
 public:
  explicit AmbientLight(double intensity);

  double intensity;
};

class PointLight : public Light {
  explicit PointLight(double intensity, Vector3d position);

  double intensity;
  Vector3d position;
};

class DirectionalLight : public Light {
  explicit DirectionalLight(double intensity, Vector3d directional);

  double intensity;
  Vector3d directional;
};


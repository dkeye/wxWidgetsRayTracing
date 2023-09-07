#pragma once

#include <wx/wx.h>

#include "Vector3d.h"

class Sphere {
 public:
  Sphere(Vector3d center, float radius, wxColour color, float specular = 0.0,
         float reflective = 0.0);

  Vector3d center;
  float radius;
  wxColour color;
  float specular;
  float reflective;
};

class Light {
 public:
  Light();
  ~Light() {}
};

class AmbientLight : public Light {
 public:
  explicit AmbientLight(float intensity);

  float intensity;
};

class PointLight : public Light {
  explicit PointLight(float intensity, Vector3d position);

  float intensity;
  Vector3d position;
};

class DirectionalLight : public Light {
  explicit DirectionalLight(float intensity, Vector3d directional);

  float intensity;
  Vector3d directional;
};


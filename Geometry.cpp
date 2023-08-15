#include "Geometry.h"

#include <wx/wx.h>

class Sphere {
 public:
  Sphere(Vector3D center, double radius, wxColour color, double specular = 0.0,
         double reflective = 0.0)
      : center(center),
        radius(radius),
        color(color),
        specular(specular),
        reflective(reflective) {}

 private:
  Vector3D center;
  double radius;
  wxColour color;
  double specular;
  double reflective;
}

Light::~Light() {
}

AmbientLight::AmbientLight(double intensity) : intensity(intensity) {}

PointLight::PointLight(double intensity, Vector3D position)
    : intensity(intensity), position(position) {}

DirectionalLight::DirectionalLight(double intensity, Vector3D directional)
    : intensity(intensity), directional(directional) {}

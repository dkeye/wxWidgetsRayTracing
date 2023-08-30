#include "Geometry.h"

#include <wx/wx.h>

Light::Light() {
  // Конструктор класса Light
}

Sphere::Sphere(Vector3d center, double radius, wxColour color, double specular,
               double reflective)
    : center(center),
      radius(radius),
      color(color),
      specular(specular),
      reflective(reflective) {}

AmbientLight::AmbientLight(double intensity) : intensity(intensity) {}

PointLight::PointLight(double intensity, Vector3d position)
    : intensity(intensity), position(position) {}

DirectionalLight::DirectionalLight(double intensity, Vector3d directional)
    : intensity(intensity), directional(directional) {}

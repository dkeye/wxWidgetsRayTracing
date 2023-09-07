#include "Geometry.h"

#include <wx/wx.h>

Light::Light() {
  // Конструктор класса Light
}

Sphere::Sphere(Vector3d center, float radius, wxColour color, float specular,
               float reflective)
    : center(center),
      radius(radius),
      color(color),
      specular(specular),
      reflective(reflective) {}

AmbientLight::AmbientLight(float intensity) : intensity(intensity) {}

PointLight::PointLight(float intensity, Vector3d position)
    : intensity(intensity), position(position) {}

DirectionalLight::DirectionalLight(float intensity, Vector3d directional)
    : intensity(intensity), directional(directional) {}

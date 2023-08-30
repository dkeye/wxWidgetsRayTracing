#pragma once

#include <wx/wx.h>

#include <tuple>
#include <vector>

#include "Camera.h"
#include "Geometry.h"

class RayTracingUtils {
 public:
  static void raytrace(double width, double height,
                       std::vector<std::vector<wxColour>>& imageColors);
  static wxColour traceRay(const Camera& camera, const Vector3d& ray,
                           double traceMin, double traceMax,
                           std::vector<Sphere>& spheres,
                           const wxColour& BACKGROUND_COLOR);
  static std::tuple<double, double> intersectSphere(
      const Camera& camera, const Vector3d& ray, const Sphere& sphere);
};

#pragma once

#include <wx/wx.h>

#include <tuple>
#include <vector>

#include "Camera.h"
#include "Geometry.h"

class RayTracingUtils {
 public:
  static void raytrace(int width, int height,
                       std::vector<std::vector<wxColour>>& imageColors);
  static wxColour traceRay(const Camera& camera, const Vector3d& ray,
                           float traceMin, float traceMax,
                           std::vector<Sphere>& spheres,
                           const wxColour& BACKGROUND_COLOR);
  static std::tuple<float, float> intersectSphere(
      const Camera& camera, const Vector3d& ray, const Sphere& sphere);
};

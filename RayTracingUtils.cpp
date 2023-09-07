#include "RayTracingUtils.h"

#include <wx/wx.h>

#include <format>
#include <tuple>
#include <vector>

#define INF std::numeric_limits<float>::max()

void RayTracingUtils::raytrace(
    int width, int height, std::vector<std::vector<wxColour>>& imageColors) {
  float aspectRatio = static_cast<float>(width) / static_cast<float>(height);
  struct viewport {
    float width = 1;
    float height = 1;
  };
  viewport myViewport = viewport{1, 1 / aspectRatio};
  wxColour BACKGROUND_COLOR = *wxBLACK;
  Camera camera(0, 0, 0);
  std::vector<Sphere> spheres = {
    Sphere(Vector3d(0, -1, 4), 1, *wxRED),
    Sphere(Vector3d(-1, 0, 5), 1, *wxGREEN),
    Sphere(Vector3d(1, 0, 6), 1, *wxBLUE)
};
  for (float Cx = -width / 2; Cx < width / 2; Cx++) {
    for (float Cy = -height / 2; Cy < height / 2; Cy++) {
      int Sx = width / 2 + Cx;
      int Sy = height / 2 - Cy - 1;
      Vector3d canvasToViewport = Vector3d(Cx * myViewport.width / width,
                                           Cy * myViewport.height / height, 1);
      wxColour pointColour =
          traceRay(camera, canvasToViewport, 1, INF, spheres, BACKGROUND_COLOR);
      imageColors[Sx][Sy] = pointColour;
    }
  }
}

wxColour RayTracingUtils::traceRay(const Camera& camera, const Vector3d& ray,
                                   float traceMin, float traceMax,
                                   std::vector<Sphere>& spheres,
                                   const wxColour& BACKGROUND_COLOR) {
  float closest_t = traceMax;
  Sphere* closest_sphere = nullptr;

  for (Sphere& sphere : spheres) {
    auto [t1, t2] = intersectSphere(camera, ray, sphere);
    if (t1 < closest_t && t1 > traceMin && t1 < traceMax) {
      closest_t = t1;
      closest_sphere = &sphere;
    }
    if (t2 < closest_t && t2 > traceMin && t2 < traceMax) {
      closest_t = t2;
      closest_sphere = &sphere;
    }
  }

  if (closest_sphere != nullptr && closest_sphere->radius > 0) {
    return closest_sphere->color;
  }
  return BACKGROUND_COLOR;
}

std::tuple<float, float> RayTracingUtils::intersectSphere(
    const Camera& camera, const Vector3d& ray, const Sphere& sphere) {
  Vector3d Co = camera - sphere.center;
  float k1 = ray * ray;
  float k2 = 2 * (Co * ray);
  float k3 = (Co * Co) - sphere.radius * sphere.radius;

  float discriminant = k2 * k2 - 4 * k1 * k3;
  if (discriminant < 0) {
    return {INF, INF};
  }
  float t1 = (-k2 + std::sqrt(discriminant)) / (2 * k1);
  float t2 = (-k2 - std::sqrt(discriminant)) / (2 * k1);
  return {t1, t2};
}

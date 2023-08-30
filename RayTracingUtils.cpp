#include "RayTracingUtils.h"

#include <wx/wx.h>

#include <tuple>
#include <vector>

#define INF std::numeric_limits<double>::max()


void RayTracingUtils::raytrace(
    double width, double height,
    std::vector<std::vector<wxColour>>& imageColors) {
  struct viewport {
    double width = 1;
    double height = 1;
  };
  wxColour BACKGROUND_COLOR = *wxWHITE;
  Camera camera(width / 2, height / 2, 0);

  std::vector<Sphere> spheres = {Sphere(Vector3d(200, 600, 4), 1, *wxRED),
                                 Sphere(Vector3d(600, 600, 4), 1, *wxGREEN),
                                 Sphere(Vector3d(400, 300, 3), 1, *wxBLUE)};

  for (int x = 0; x < width; x++) {
    for (int y = 0; y < height; y++) {
      imageColors[x][y] = traceRay(
          camera, Vector3d(x * viewport().width, y * viewport().height, 1), 1,
          INF, spheres, BACKGROUND_COLOR);
    }
  }
}

wxColour RayTracingUtils::traceRay(const Camera& camera, const Vector3d& ray,
                                   double traceMin, double traceMax,
                                   std::vector<Sphere>& spheres,
                                   const wxColour& BACKGROUND_COLOR) {
  double closest_t = traceMax;
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

  if (closest_sphere->radius > 0) {
    return closest_sphere->color;
  }
  return BACKGROUND_COLOR;
}

std::tuple<double, double> RayTracingUtils::intersectSphere(
    const Camera& camera, const Vector3d& ray, const Sphere& sphere) {
  Vector3d ray_direction = camera - sphere.center;
  double k1 = ray_direction * ray_direction;
  double k2 = ray_direction * ray * 2;
  double k3 = ray_direction * ray_direction - sphere.radius * sphere.radius;

  double discriminant = k2 * k2 - 4 * k1 * k3;
  if (discriminant < 0) {
    return {INF, INF};
  }
  double t1 = (-k2 + std::sqrt(discriminant)) / (2 * k1);
  double t2 = (-k2 - std::sqrt(discriminant)) / (2 * k1);
  return {t1, t2};
}

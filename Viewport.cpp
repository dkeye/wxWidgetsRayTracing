#include "Viewport.h"

class Viewport {
 public:
  explicit Viewport(double width = 1, double height = 1)
      : width(width), height(height) {}

 private:
  double width, height;
}

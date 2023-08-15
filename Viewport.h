#ifndef VIEWPORT_H
#define VIEWPORT_H

class Viewport {
 public:
  explicit Viewport(double width = 1, double height = 1);

 private:
  double width, height;
}

#endif  // VIEWPORT_H

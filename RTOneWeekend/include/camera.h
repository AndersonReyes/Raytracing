#ifndef CAMERA_H
#define CAMERA_H

#include <memory>

#include "ray.h"
#include "vec3.h"

namespace raytracer {

class SimpleCamera {
 public:
  SimpleCamera(int imageHeight_m, int imageWidth_m);

  const std::unique_ptr<Ray> CastRay(double u, double v) const;

 private:
  const int imageHeight;
  const int imageWidth;
  const double viewportWidth;
  const double viewportHeight;
  const double focalLength;
  const double aspectRatio;
  const Vector3 origin;
  Vector3 horizontal;
  Vector3 vertical;
  Vector3 lowerLeftCorner;
};

}  // namespace raytracer

#endif

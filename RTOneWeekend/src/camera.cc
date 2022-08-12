#include "camera.h"

#include <memory>

#include "vec3.h"

namespace raytracer {

SimpleCamera::SimpleCamera(int imageHeight_m, int imageWidth_m) : aspectRatio(16.0 / 9.0), imageHeight(imageHeight_m), imageWidth(imageWidth_m), viewportHeight(2.0), viewportWidth(16.0 * 2.0 / 9.0), focalLength(1.0), origin(Vector3{0, 0, 0}) {
  horizontal = Vector3{viewportWidth, 0.0, 0.0};
  vertical = Vector3(0, viewportHeight, 0);
  lowerLeftCorner = origin - 0.5 * horizontal - 0.5 * vertical - Vector3{0, 0, focalLength};
}

const std::unique_ptr<Ray> SimpleCamera::CastRay(double u, double v) const {
  return std::unique_ptr<Ray>(new Ray{origin, lowerLeftCorner + u * horizontal + v * vertical - origin});
}
}  // namespace raytracer

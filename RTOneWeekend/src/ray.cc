#include "ray.h"

namespace raytracer {
Ray::Ray() {}
Ray::Ray(const Point& m_origin, const Vector3& m_direction) : origin(m_origin), direction(m_direction) {}

Vector3 Ray::GetDirection() const {
  return direction;
}

Vector3 Ray::GetOrigin() const {
  return origin;
}

Point Ray::at(double t) const {
  return origin + t * direction;
}
}  // namespace raytracer

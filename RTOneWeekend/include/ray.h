#ifndef RAY_H
#define RAY_H

#include "point.h"
#include "vec3.h"

namespace raytracer {

class Ray {
 public:
  Ray();
  Ray(const Point& m_origin, const Vector3& m_direction);

  Vector3 GetOrigin() const;
  Vector3 GetDirection() const;
  Point at(double t) const;

 private:
  Point origin;
  Vector3 direction;
};

}  // namespace raytracer

#endif

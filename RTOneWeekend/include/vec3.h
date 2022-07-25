#ifndef VECTOR3_H
#define VECTOR3_H

#include <cassert>
#include <cmath>

namespace raytracer {
class Vector3 {
 public:
  Vector3() : elem{0, 0, 0} {}
  Vector3(double x, double y, double z) : elem{x, y, z} {}

  const double GetX() const {
    return elem[0];
  }

  const double GetY() const {
    return elem[1];
  }

  const double GetZ() const {
    return elem[2];
  }

  Vector3 operator-() const {
    return Vector3{-elem[0], -elem[1], -elem[2]};
  }

  const double operator[](int i) const {
    assert(0 <= i && i <= 2);
    return elem[i];
  }

  Vector3& operator+=(const Vector3& v) {
    elem[0] += v[0];
    elem[1] += v[1];
    elem[2] += v[2];

    return *this;
  }

  Vector3& operator/=(const Vector3& v) {
    elem[0] /= v[0];
    elem[1] /= v[1];
    elem[2] /= v[2];

    return *this;
  }

  Vector3& operator/=(double t) {
    elem[0] /= t;
    elem[1] /= t;
    elem[2] /= t;

    return *this;
  }

  Vector3& operator*=(const Vector3& v) {
    elem[0] *= v[0];
    elem[1] *= v[1];
    elem[2] *= v[2];

    return *this;
  }

  const double Length() const {
    return std::sqrt(LengthSquared());
  }

  const double LengthSquared() const {
    return elem[0] * elem[0] + elem[1] * elem[1] + elem[2] * elem[2];
  }

  static const double Dot(const Vector3& u, const Vector3& v) {
    return u[0] * v[0] + u[1] * v[1] + u[2] * v[2];
  }

  static const Vector3 Cross(const Vector3& u, const Vector3& v) {
    return Vector3(u.elem[1] * v.elem[2] - u.elem[2] * v.elem[1],
                   u.elem[2] * v.elem[0] - u.elem[0] * v.elem[2],
                   u.elem[0] * v.elem[1] - u.elem[1] * v.elem[0]);
  }

 private:
  double elem[3];
};

inline Vector3 operator+(const Vector3& u, const Vector3& v) {
  return Vector3{u[0] + v[0], u[1] + v[1], u[2] + v[2]};
}

inline Vector3 operator-(const Vector3& u, const Vector3& v) {
  return Vector3{u[0] - v[0], u[1] - v[1], u[2] - v[2]};
}

inline Vector3 operator*(const Vector3& u, const Vector3& v) {
  return Vector3{u[0] * v[0], u[1] * v[1], u[2] * v[2]};
}

inline Vector3 operator/(const Vector3& u, const Vector3& v) {
  return Vector3{u[0] / v[0], u[1] / v[1], u[2] / v[2]};
}

}  // namespace raytracer
#endif

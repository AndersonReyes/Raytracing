#ifndef VECTOR3_H
#define VECTOR3_H

#include <cassert>
#include <cmath>

namespace raytracer {
class Vector3 {
 public:
  Vector3() : elem{0, 0, 0} {}
  Vector3(double x, double y, double z) : elem{x, y, z} {}

  const double GetX() const;
  const double GetY() const;

  const double GetZ() const;

  Vector3 operator-() const;
  const double operator[](int i) const;
  Vector3& operator+=(const Vector3& v);
  Vector3& operator/=(const Vector3& v);

  Vector3& operator/=(double t);
  Vector3& operator*=(const Vector3& v);

  const double Length() const;

  const double LengthSquared() const;

  static const double Dot(const Vector3& u, const Vector3& v);
  static const Vector3 Cross(const Vector3& u, const Vector3& v);

 private:
  double elem[3];
};

Vector3 operator+(const Vector3& u, const Vector3& v);
Vector3 operator-(const Vector3& u, const Vector3& v);
Vector3 operator*(const Vector3& u, const Vector3& v);

Vector3 operator/(const Vector3& u, const Vector3& v);

}  // namespace raytracer
#endif

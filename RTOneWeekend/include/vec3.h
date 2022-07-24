#ifndef VECTOR3_H
#define VECTOR3_H

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

 private:
  double elem[3];
};

#endif

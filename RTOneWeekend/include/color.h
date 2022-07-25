#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "vec3.h"

namespace raytracer {

using Color = Vector3;

void WriteColor(std::ostream &out, Color color) {
  out << static_cast<int>(255.999 * color.GetX()) << ' '
      << static_cast<int>(255.999 * color.GetY()) << ' '
      << static_cast<int>(255.999 * color.GetZ()) << '\n';
}
}  // namespace raytracer

#endif

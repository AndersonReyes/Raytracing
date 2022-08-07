#ifndef COLOR_H
#define COLOR_H

#include <iostream>

#include "vec3.h"

namespace raytracer {

using Color = Vector3;

void WriteColor(std::ostream &out, Color color);
}  // namespace raytracer

#endif

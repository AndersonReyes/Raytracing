#include "color.h"

namespace raytracer {
void WriteColor(std::ostream &out, Color color) {
  out << static_cast<int>(255.999 * color.GetX()) << ' '
      << static_cast<int>(255.999 * color.GetY()) << ' '
      << static_cast<int>(255.999 * color.GetZ()) << '\n';
}
}  // namespace raytracer

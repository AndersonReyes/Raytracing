#include <iostream>
#include <memory>

#include "camera.h"
#include "color.h"
#include "ray.h"
#include "vec3.h"

raytracer::Color ray_color(const raytracer::Ray& r) {
  raytracer::Vector3 unitDirection = r.GetDirection().Unit();
  auto t = 0.5 * (unitDirection.GetY() + 1.0);
  return (1.0 - t) * raytracer::Color(1.0, 1.0, 1.0) + t * raytracer::Color(0.5, 0.7, 1.0);
}

int main() {
  // Image
  const int image_width{400};
  const int image_height{235};

  // Camera
  const raytracer::SimpleCamera camera{image_height, image_width};

  // Render

  std::cout << "P3\n"
            << image_width << ' ' << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    for (int i = 0; i < image_width; ++i) {
      auto u = double(i) / (image_width - 1);
      auto v = double(j) / (image_height - 1);
      auto ray = camera.CastRay(u, v);
      raytracer::Color color = ray_color(*ray.get());

      raytracer::WriteColor(std::cout, color);
    }
  }
}

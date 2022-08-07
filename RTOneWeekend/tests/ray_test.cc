#include "../include/ray.h"

#include <gtest/gtest.h>

#include <cmath>

#include "../include/point.h"

using namespace raytracer;

class RayTest : public ::testing::Test {
 protected:
  void SetUp() override {
    ray = Ray{ Point{1, 2, 3}, Vector3{4, 5, 6}};
  }

  Ray ray;
};

TEST_F(RayTest, ContainsOriginAndDirection) {
  EXPECT_DOUBLE_EQ(ray.GetOrigin().GetX(), 1.0);
  EXPECT_DOUBLE_EQ(ray.GetOrigin().GetY(), 2.0);
  EXPECT_DOUBLE_EQ(ray.GetOrigin().GetZ(), 3.0);

  EXPECT_DOUBLE_EQ(ray.GetDirection().GetX(), 4.0);
  EXPECT_DOUBLE_EQ(ray.GetDirection().GetY(), 5.0);
  EXPECT_DOUBLE_EQ(ray.GetDirection().GetZ(), 6.0);
}

TEST_F(RayTest, At) {
  Point newPos = ray.at(2.0);

  EXPECT_DOUBLE_EQ(newPos.GetX(), 9.0);
  EXPECT_DOUBLE_EQ(newPos.GetY(), 12.0);
  EXPECT_DOUBLE_EQ(newPos.GetZ(), 15.0);
}

#include <gtest/gtest.h>

#include "../include/vec3.h"

TEST(Vector3, Contains3Components) {
  Vector3 vec{1, 2, 3};

  EXPECT_DOUBLE_EQ(vec.GetX(), 1.0);
  EXPECT_DOUBLE_EQ(vec.GetY(), 2.0);
  EXPECT_DOUBLE_EQ(vec.GetZ(), 3.0);
}

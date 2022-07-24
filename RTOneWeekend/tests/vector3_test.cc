#include <gtest/gtest.h>

#include <cmath>

#include "../include/vec3.h"

using namespace raytracer;

class Vector3Test : public ::testing::Test {
 protected:
  void SetUp() override {
    vec = Vector3{1, 2, 3};
  }

  Vector3 vec;
};

TEST_F(Vector3Test, Contains3Components) {
  EXPECT_DOUBLE_EQ(vec.GetX(), 1.0);
  EXPECT_DOUBLE_EQ(vec.GetY(), 2.0);
  EXPECT_DOUBLE_EQ(vec.GetZ(), 3.0);
}

TEST_F(Vector3Test, NegateOperatorWorks) {
  Vector3 negated = -vec;

  EXPECT_DOUBLE_EQ(negated.GetX(), -1.0);
  EXPECT_DOUBLE_EQ(negated.GetY(), -2.0);
  EXPECT_DOUBLE_EQ(negated.GetZ(), -3.0);
}

TEST_F(Vector3Test, IndexOperatorWorks) {
  EXPECT_DOUBLE_EQ(vec[0], 1.0);
  EXPECT_DOUBLE_EQ(vec[1], 2.0);
  EXPECT_DOUBLE_EQ(vec[2], 3.0);

  EXPECT_DEATH({
    vec[4];
  },
               "Assertion `0 <= i && i <= 2' failed");

  EXPECT_DEATH({
    vec[-1];
  },
               "Assertion `0 <= i && i <= 2' failed");
}

TEST_F(Vector3Test, PlusOperatorInplaceWorks) {
  vec += Vector3{4, 5, 6};

  EXPECT_DOUBLE_EQ(vec[0], 5.0);
  EXPECT_DOUBLE_EQ(vec[1], 7.0);
  EXPECT_DOUBLE_EQ(vec[2], 9.0);
}

TEST_F(Vector3Test, DivOperatorInplaceWorks) {
  vec /= Vector3{4, 2, -6};

  EXPECT_DOUBLE_EQ(vec[0], 1.0 / 4.0);
  EXPECT_DOUBLE_EQ(vec[1], 1.0);
  EXPECT_DOUBLE_EQ(vec[2], -0.5);
}

TEST_F(Vector3Test, MultOperatorInplaceWorks) {
  vec *= Vector3{4, 5, 6};

  EXPECT_DOUBLE_EQ(vec[0], 4.0);
  EXPECT_DOUBLE_EQ(vec[1], 10.0);
  EXPECT_DOUBLE_EQ(vec[2], 18.0);
}

TEST_F(Vector3Test, Scale) {
  vec /= 2;

  EXPECT_DOUBLE_EQ(vec[0], 0.5);
  EXPECT_DOUBLE_EQ(vec[1], 1.0);
  EXPECT_DOUBLE_EQ(vec[2], 1.5);
}

TEST_F(Vector3Test, Length) {
  double l = vec.Length();

  EXPECT_DOUBLE_EQ(l, std::sqrt(1 + 4 + 9));
}

TEST_F(Vector3Test, LengthSquared) {
  double l_squared = vec.LengthSquared();

  EXPECT_DOUBLE_EQ(l_squared, 1.0 + 4.0 + 9.0);
}

TEST_F(Vector3Test, AddTwoVectors) {
  Vector3 r = vec + Vector3{4, 5, 6};

  EXPECT_DOUBLE_EQ(r[0], 5.0);
  EXPECT_DOUBLE_EQ(r[1], 7.0);
  EXPECT_DOUBLE_EQ(r[2], 9.0);
}

TEST_F(Vector3Test, SubtractTwoVectors) {
  Vector3 r = vec - Vector3{4, 1, 6};

  EXPECT_DOUBLE_EQ(r[0], -3.0);
  EXPECT_DOUBLE_EQ(r[1], 1.0);
  EXPECT_DOUBLE_EQ(r[2], -3.0);
}

TEST_F(Vector3Test, DivTwoVectors) {
  Vector3 r = vec / Vector3{4, 2, -6};

  EXPECT_DOUBLE_EQ(r[0], 1.0 / 4.0);
  EXPECT_DOUBLE_EQ(r[1], 1.0);
  EXPECT_DOUBLE_EQ(r[2], -0.5);
}

TEST_F(Vector3Test, MultiplyTwoVectors) {
  Vector3 r = vec * Vector3{4, 5, 6};

  EXPECT_DOUBLE_EQ(r[0], 4.0);
  EXPECT_DOUBLE_EQ(r[1], 10.0);
  EXPECT_DOUBLE_EQ(r[2], 18.0);
}

TEST_F(Vector3Test, DotProduct) {
  double r = Vector3::Dot(vec, Vector3{4, 5, 6});

  EXPECT_DOUBLE_EQ(r, 4 + 10 + 18);
}

TEST_F(Vector3Test, CrossProduct) {
  Vector3 v = Vector3::Cross(vec, Vector3{4, 5, 6});

  EXPECT_DOUBLE_EQ(v[0], -3);
  EXPECT_DOUBLE_EQ(v[1], 6);
  EXPECT_DOUBLE_EQ(v[2], -3);
}

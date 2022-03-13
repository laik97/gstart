#include "gtest/gtest.h"
#include "shapes/workerShape.h"

TEST(TestWorkerShape, InitialTestDirections)
{
  Directions dir;
  EXPECT_FALSE(dir.left_);
  EXPECT_FALSE(dir.right_);
  EXPECT_FALSE(dir.forward_);
  EXPECT_FALSE(dir.backward_);
}

TEST(TestWorkerShape, TestDirectionsTrue)
{
  Directions dir;
  dir.left();
  dir.right();
  dir.forward();
  dir.backward();
  EXPECT_TRUE(dir.left_);
  EXPECT_TRUE(dir.right_);
  EXPECT_TRUE(dir.forward_);
  EXPECT_TRUE(dir.backward_);
}

TEST(TestWorkerShape, TestDirectionsFalse)
{
  Directions dir;
  dir.left(false);
  dir.right(false);
  dir.forward(false);
  dir.backward(false);
  EXPECT_FALSE(dir.left_);
  EXPECT_FALSE(dir.right_);
  EXPECT_FALSE(dir.forward_);
  EXPECT_FALSE(dir.backward_);
}

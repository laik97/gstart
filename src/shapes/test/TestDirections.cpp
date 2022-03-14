#include "gtest/gtest.h"
#include "shapes/workerShape.h"

TEST(TestDirections, InitialDirections)
{
  Directions dir;
  EXPECT_FALSE(dir.left_);
  EXPECT_FALSE(dir.right_);
  EXPECT_FALSE(dir.forward_);
  EXPECT_FALSE(dir.backward_);
}

TEST(TestDirections, DirectionsMove)
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

TEST(TestDirections, DirectionsStop)
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

TEST(TestDirections, DirectionsClear)
{
  Directions dir;
  dir.left(true);
  dir.right(true);
  dir.forward(true);
  dir.backward(true);
  dir.clear();
  EXPECT_FALSE(dir.left_);
  EXPECT_FALSE(dir.right_);
  EXPECT_FALSE(dir.forward_);
  EXPECT_FALSE(dir.backward_);
}
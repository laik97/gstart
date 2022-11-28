#include <math.h>

#include "gtest/gtest.h"
#include "shapes/transformations.h"
#include "shapes/workerShape.h"

namespace {
  class TestWorkerShape : public ::testing::Test
  {
    protected:
    sf::Vector2f startPosition{ 0.0, 0.0 };
    double startOrientation{ 0.0 };
    WorkerShape workerShape{ startPosition, startOrientation };
  };

}  // namespace

TEST_F(TestWorkerShape, WorkerConstruction) {
  EXPECT_EQ(workerShape.getCurrentPosition().x, 0.0);
  EXPECT_EQ(workerShape.getCurrentPosition().y, 0.0);
  EXPECT_EQ(workerShape.getCurrentOrientation(), 0.0);
}

TEST_F(TestWorkerShape, WorkerMoveForward) {
  workerShape.move(Direction::forward);
  EXPECT_EQ(workerShape.getCurrentPosition().x, 1.0);
  EXPECT_EQ(workerShape.getCurrentPosition().y, 0.0);
  EXPECT_EQ(workerShape.getCurrentOrientation(), 0.0);
}

TEST_F(TestWorkerShape, WorkerRotateLeft90deg) {
  for (int i = 0; i < 45; i++)
  { workerShape.move(Direction::left); }

  EXPECT_EQ(workerShape.getCurrentPosition().x, 0.0);
  EXPECT_EQ(workerShape.getCurrentPosition().y, 0.0);
  EXPECT_EQ(workerShape.getCurrentOrientation(), 270.0);
}

TEST_F(TestWorkerShape, WorkerRotateRight90deg) {
  for (int i = 0; i < 45; i++)
  { workerShape.move(Direction::right); }

  EXPECT_EQ(workerShape.getCurrentPosition().x, 0.0);
  EXPECT_EQ(workerShape.getCurrentPosition().y, 0.0);
  EXPECT_EQ(workerShape.getCurrentOrientation(), 90.0);
}

TEST_F(TestWorkerShape, WorkerComplexMovement) {
  for (int i = 0; i < 15; i++)
  { workerShape.move(Direction::right); }

  workerShape.move(Direction::forward);
  float angle = Transformation::transform<Unit::degrees, Unit::radians>(30.0f);

  const float sin30 = std::sin(angle);
  const float cos30 = std::cos(angle);

  EXPECT_EQ(workerShape.getCurrentPosition().x, sin30 * 1.0);
  EXPECT_EQ(workerShape.getCurrentPosition().y, cos30 * 1.0);
  EXPECT_EQ(workerShape.getCurrentOrientation(), 90.0);
}

#include "gtest/gtest.h"
#include "shapes/workerShape.h"

namespace
{
  class TestWorkerShape : public ::testing::Test
  {
    protected:
    const sf::Vector2f startPosition{ 0.0, 0.0 };
    const double startOrientation{ 0.0 };
    WorkerShape workerShape;

    void SetUp()
    {
      WorkerShape workerShape{ startPosition, startOrientation };
    }

    void TearDown()
    {
    }
  };

}  // namespace

TEST_F(TestWorkerShape, Constructor)
{
  EXPECT_EQ(workerShape.getCurrentPosition().x, 0.0);
  EXPECT_EQ(workerShape.getCurrentPosition().y, 0.0);
  EXPECT_EQ(workerShape.getCurrentOrientation(), 0.0);
}
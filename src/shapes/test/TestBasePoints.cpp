#include "gtest/gtest.h"
#include "shapes/workerShape.h"

TEST(TestWorkerBaseShape, BasePointsDefinitions)
{
  EXPECT_EQ(WorkerBaseShape::frontBasePoint[0], 8.0);
  EXPECT_EQ(WorkerBaseShape::frontBasePoint[1], 2.5);
  EXPECT_EQ(WorkerBaseShape::backUpBasePoint[0], 0.0);
  EXPECT_EQ(WorkerBaseShape::backUpBasePoint[1], 0.0);
  EXPECT_EQ(WorkerBaseShape::backDownBasePoint[0], 0.0);
  EXPECT_EQ(WorkerBaseShape::backDownBasePoint[1], 5.0);
}

TEST(TestWorkerBaseShape, BasePointsGetters)
{
  EXPECT_EQ(WorkerBaseShape::getFrontBasePoint().x, 8.0);
  EXPECT_EQ(WorkerBaseShape::getFrontBasePoint().y, 2.5);
  EXPECT_EQ(WorkerBaseShape::getBackUpBasePoint().x, 0.0);
  EXPECT_EQ(WorkerBaseShape::getBackUpBasePoint().y, 0.0);
  EXPECT_EQ(WorkerBaseShape::getBackDownBasePoint().x, 0.0);
  EXPECT_EQ(WorkerBaseShape::getBackDownBasePoint().y, 5.0);
}

TEST(TestWorkerBaseShape, OriginPointGetter)
{
  EXPECT_EQ(WorkerBaseShape::getOrigin().x, 4.0);
  EXPECT_EQ(WorkerBaseShape::getOrigin().y, 2.5);
}
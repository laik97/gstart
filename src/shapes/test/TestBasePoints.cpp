#include "gtest/gtest.h"
#include "shapes/workerShape.h"

TEST(TestWorkerBaseShape, BasePointsGetters) {
  WorkerBaseShape shape;
  EXPECT_EQ(shape.getFrontBasePoint().x, 8.0);
  EXPECT_EQ(shape.getFrontBasePoint().y, 2.5);
  EXPECT_EQ(shape.getBackUpBasePoint().x, 0.0);
  EXPECT_EQ(shape.getBackUpBasePoint().y, 0.0);
  EXPECT_EQ(shape.getBackDownBasePoint().x, 0.0);
  EXPECT_EQ(shape.getBackDownBasePoint().y, 5.0);
}

TEST(TestWorkerBaseShape, OriginPointGetter) {
  WorkerBaseShape shape;
  EXPECT_EQ(shape.getOrigin().x, 4.0);
  EXPECT_EQ(shape.getOrigin().y, 2.5);
}
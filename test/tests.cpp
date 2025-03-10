// Copyright 2025 UNN-CS Team
#include <gtest/gtest.h>
#include "circle.h"
#include "tasks.h"

TEST(CircleTest, ConstructorAndGetters) {
  Circle c(5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 5);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 5 * 5);
}

TEST(CircleTest, SetRadius) {
  Circle c(1);
  c.setRadius(10);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 10);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 10 * 10);
}

TEST(CircleTest, SetFerence) {
  Circle c(1);
  c.setFerence(2 * M_PI * 4);
  EXPECT_DOUBLE_EQ(c.getRadius(), 4);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 4);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 4 * 4);
}

TEST(CircleTest, SetArea) {
  Circle c(1);
  c.setArea(M_PI * 6 * 6);
  EXPECT_DOUBLE_EQ(c.getRadius(), 6);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2 * M_PI * 6);
  EXPECT_DOUBLE_EQ(c.getArea(), M_PI * 6 * 6);
}

TEST(CircleTest, ZeroRadius) {
  Circle c(0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 0);
  EXPECT_DOUBLE_EQ(c.getArea(), 0);
}

TEST(CircleTest, NegativeRadius) {
  Circle c(-5);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(CircleTest, NegativeFerence) {
  Circle c(1);
  c.setFerence(-10);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(CircleTest, NegativeArea) {
  Circle c(1);
  c.setArea(-20);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0);
}

TEST(CircleTest, LargeValues) {
  Circle c(1e6);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e6, 1e-6);
  EXPECT_NEAR(c.getArea(), M_PI * 1e6 * 1e6, 1e-6);
}

TEST(CircleTest, SmallValues) {
  Circle c(1e-6);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 1e-6, 1e-12);
  EXPECT_NEAR(c.getArea(), M_PI * 1e-6 * 1e-6, 1e-12);
}

TEST(TaskTest, RopeGap) {
  double gap = ropeGap();
  EXPECT_NEAR(gap, 0.159154943, 1e-6);
}

TEST(TaskTest, ConcreteCost) {
  EXPECT_NEAR(calcConcreteCost(), 21991.148575, 1e-6);
}

TEST(TaskTest, FenceCost) { EXPECT_NEAR(calcFenceCost(), 50265.48246, 1e-6); }

TEST(TaskTest, MinPoolSize) {
  Circle pool(0);
  Circle outer(1);
  double trackArea = outer.getArea() - pool.getArea();
  EXPECT_DOUBLE_EQ(trackArea, M_PI * 1 * 1);
}

TEST(TaskTest, LargePoolSize) {
  Circle pool(1000);
  Circle outer(1001);
  double trackArea = outer.getArea() - pool.getArea();
  EXPECT_NEAR(trackArea, M_PI * (1001 * 1001 - 1000 * 1000), 1e-6);
}

TEST(CircleTest, FerencePrecision) {
  Circle c(7);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 7, 1e-6);
}

TEST(CircleTest, AreaPrecision) {
  Circle c(3.5);
  EXPECT_NEAR(c.getArea(), M_PI * 3.5 * 3.5, 1e-6);
}

TEST(CircleTest, SetAreaAndCheckFerence) {
  Circle c(1);
  c.setArea(M_PI * 8 * 8);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 8, 1e-6);
}

TEST(CircleTest, SetFerenceAndCheckArea) {
  Circle c(1);
  c.setFerence(2 * M_PI * 5);
  EXPECT_NEAR(c.getArea(), M_PI * 5 * 5, 1e-6);
}

TEST(CircleTest, SetRadiusAndCheckFerenceArea) {
  Circle c(2);
  c.setRadius(9);
  EXPECT_NEAR(c.getFerence(), 2 * M_PI * 9, 1e-6);
  EXPECT_NEAR(c.getArea(), M_PI * 9 * 9, 1e-6);
}

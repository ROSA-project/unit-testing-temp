#include "gtest/gtest.h"
#include "geometry_functions.h"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect equality.
  EXPECT_EQ(sum_double(3,1.5), 4.5);
  EXPECT_EQ(sum_double(3,0), 3);
}
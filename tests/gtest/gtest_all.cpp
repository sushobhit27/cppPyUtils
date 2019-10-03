#include "gtest/gtest.h"
#include "../../src/utils.hpp"

TEST(IsInTest, StringVectorPositive) {
    std::vector<std::string> vec { "a", "b", "c", "d"};

    EXPECT_EQ (true, is_in(std::string("c"), vec));
    EXPECT_EQ (true, is_in(std::string("a"), vec));
    EXPECT_EQ (true, is_in(std::string("d"), vec));
}

TEST(IsInTest, StringVectorFalseNegative) {
    std::vector<std::string> vec { "a", "b", "c", "d"};

    EXPECT_EQ (false, is_in(std::string("e"), vec));
    EXPECT_EQ (false, is_in(std::string(""), vec));
    EXPECT_EQ (false, is_in(std::string("abc"), vec));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
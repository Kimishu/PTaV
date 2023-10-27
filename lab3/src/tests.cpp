//
// Created by Kimihito on 26.10.2023.
//

#include <gtest/gtest.h>
#include "RectangleChecker/RectangleChecker.h"

//Constructor tests
TEST(RectangleCheckerConstructorTest, NegativeSideValue){
    EXPECT_THROW(RectangleChecker({-4,4,4,4},{90,90,90,90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, NegativeSidesValues){
    EXPECT_THROW(RectangleChecker({-4,-5,-4,-5},{90,90,90,90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, NegativeAngleValue){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{-90,90,90,90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, NegativeAnglesValues){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{-90,790,-90,-90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, ZeroSideValue){
    EXPECT_THROW(RectangleChecker({4,4,4,0},{-90,790,-90,-90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, ZeroSidesValues){
    EXPECT_THROW(RectangleChecker({4,4,4,0},{-90,790,-90,-90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, ZeroAngleValue){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{90,0,90,90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, ZeroAnglesValues){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{0,0,0,0}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, MaxAngleValue){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{360,90,90,90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, MaxAnglesValues){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{360,360,360,360}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, MoreThanMaxAngleValue){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{378,90,90,90}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, MoreThanMaxAnglesValues){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{378,378,378,378}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, SumLessThanMax){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{30,20,10,40}),std::invalid_argument);
}

TEST(RectangleCheckerConstructorTest, SumMoreThanMax){
    EXPECT_THROW(RectangleChecker({4,4,4,4},{30,20,10,40}),std::invalid_argument);
}


//Type tests

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

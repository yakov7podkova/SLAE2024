#include <iostream>
#include <gtest/gtest.h>
#include "../src/thomas_method.cpp"

vd d = {7.0, 7.0, 7.0}; // for comfort we have one global free member of SLAE with different matrixes

TEST(diagonal_3x3, HandlesAnswer) {

    vd main = {9, 9, 9};
    vd low = {0, 0, 0};
    vd high = {0, 0, 0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = {7.0 / 9.0, 7.0 / 9.0, 7.0 / 9.0};

    EXPECT_EQ(ans, expected_ans);
    
};


TEST(symmetric_3x3, HandlesAnswer) {

    vd main = {8.0, 8.0, 8.0};
    vd low = {0, 2.0, 2.0};
    vd high = {2.0, 2.0, 0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = {3.0 / 4.0, 1.0 / 2.0, 3.0 / 4.0};

    EXPECT_EQ(ans[2], expected_ans[2]);

};





//int main(int argc, char **argv) {
//    ::testing::InitGoogleTest(&argc, argv);
//    return RUN_ALL_TESTS();

//};

//#include <iostream>
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
    
    for (std::size_t i = 0; i < ans.size(); i++) { EXPECT_DOUBLE_EQ(ans[i], expected_ans[i]); }
    
};


TEST(symmetric_3x3, HandlesAnswer) {

    vd main = {8.0, 8.0, 8.0};
    vd low = {0, 2.0, 2.0};
    vd high = {2.0, 2.0, 0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = {3.0 / 4.0, 1.0 / 2.0, 3.0 / 4.0};
    
    for (std::size_t i = 0; i < ans.size(); i++) { EXPECT_DOUBLE_EQ(ans[i], expected_ans[i]); }

};

TEST(random_3x3, HandlesAnswer) {
    
    vd main = {8.0, 8.0, -9.0};
    vd low = {0, -1.0, 6.0};
    vd high = {4.0, 3.0, 0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = {7.0 / 18.0, 35.0 / 36.0, -7.0 / 54.0};

    for (std::size_t i = 0; i < ans.size(); i++) { EXPECT_DOUBLE_EQ(ans[i], expected_ans[i]); }
};

TEST(random_3x3_harder, HandlesAnswer) {
    
    vd main = {8.2, 8.3, 9.2};
    vd low = {0, 1.6, 5.7};
    vd high = {4.6, 2.9, 0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = { 0.510648, 0.611453, 0.382034};

    for (std::size_t i = 0; i < ans.size(); i++) { EXPECT_NEAR(ans[i], expected_ans[i], 0.000001); }

};

TEST(random_3x3_BigNumbers, HandlesAnswer) {

    vd main = {88878.0, 83765.0, 925000.0};
    vd low = {0.0, -168.0, 57965.0};
    vd high = {4679.0, 2.9, 0.0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = { 0.0000743524, 0.0000837162, 0.00000232232};

    for (std::size_t i = 0; i < ans.size(); i++) { EXPECT_NEAR(ans[i], expected_ans[i], 0.000001); }

};


TEST(random_3x3_IncorrectMatrix, HandlesAnswer) {

    vd main = {8.0, 8.0, 1.0};
    vd low = {0.0, -1.0, 6.0};
    vd high = {4.0, 3.0, 0.0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = { 35.0 / 106.0, 231.0 / 212.0, -49.0 / 106.0};

    for (std::size_t i = 0; i < ans.size(); i++) { EXPECT_NE(ans[i], expected_ans[i]); }

};


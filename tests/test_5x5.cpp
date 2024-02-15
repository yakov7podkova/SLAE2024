#include <iostream>
#include <gtest/gtest.h>
#include "../src/thomas_method.cpp"

vd d = {2.0, 2.0, 2.0, 2.0, 2.0};

TEST(random_5x5, HandlesAnswer) {

    vd main = {15.0, 12.0, 19.0, 10.0, 2.0};
    vd low = {0.0, 4.5, 3.0, 2.0, -1.0};
    vd high = {2.0, -2.0, 5.5, 7.0, 0.0};

    TDM Mat(main, low, high);

    vd ans = thomas_method(Mat, d);
    vd expected_ans = {3236.0/28797.0, 1509.0/9599.0, 1882.0/9599.0, (-3834.0)/9599.0, 7682.0/9599.0};

    for (std::size_t i = 0; i < ans.size(); i++) { EXPECT_NEAR(ans[i], expected_ans[i], 0.000001); }

};

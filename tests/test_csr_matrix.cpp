#include <iostream>
#include <gtest/gtest.h>
#include "../src/CSR_matrix.h"


std::vector<double> elems = {10, 20, 0, 0, 0, 0, 0, 30, 0, 40, 0, 0, 0, 0, 50, 60, 70, 0, 0, 0, 0, 0, 0, 80};
size_t ncols = 6;

CSR Mat(elems, ncols);


TEST(sparse_elem_by_index, HandlesAnswer) {

    EXPECT_DOUBLE_EQ(Mat(0,0), 10);
    EXPECT_DOUBLE_EQ(Mat(0,1), 20);
    EXPECT_DOUBLE_EQ(Mat(1,1), 30);
    EXPECT_DOUBLE_EQ(Mat(2,3), 60);
    EXPECT_DOUBLE_EQ(Mat(3, 5), 80);

}

TEST(sparse_vector_multiplication, HandlesAnswer) {

    std::vector<double> vec(6, 1);
    std::vector<double> ans = Mat*vec;

    std::vector<double> expected_ans = {30, 70, 180, 80};

    for (size_t i = 0; i < expected_ans.size(); i++) {
        EXPECT_DOUBLE_EQ(ans[i], expected_ans[i]);
    }

}



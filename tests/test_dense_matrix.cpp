#include <gtest/gtest.h>
#include "../src/dense_matrix.h"


TEST(Mat_3x3, HandlesAnswer) {

std::vector<double> expected_ans = {14, 21, -14, 0, 175, -70, 0, 0, 35};
denseMatrix expectedMat(expected_ans, 3);

for (size_t i = 0; i < expectedMat.getColumns(); i++) {
	for (size_t j = 0; j < expectedMat.getColumns(); j++) {
		EXPECT_DOUBLE_EQ(expectedMat(i, j), expected_ans[i]);
	}
}

}
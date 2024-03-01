#include <gtest/gtest.h>
#include "../src/householder_method.h"

std::vector<double> vec = {12, -51, 4, 6, 167, -68, -4, 24, -41};
denseMatrix Mat(vec, 3);

TEST(Rmatrix_3x3, HandlesAnswer) {

std::vector<double> expected_ans = {14, 21, -14, 0, 175, -70, 0, 0, 35};
denseMatrix expectedMat(expected_ans, 3);

denseMatrix ans = Rmatrix(Mat);

for (size_t i = 0; i < expectedMat.getColumns(); i++) {
	for (size_t j = 0; j < expectedMat.getColumns(); j++) {
		EXPECT_DOUBLE_EQ(ans(i, j), expectedMat(i, j));
	}
}

}


// TEST(Pmultiply_3x3, HandlesAnswer) {

// // std::vector<double> expected_ans = {14, 21, -14, 0, 175, -70, 0, 0, 35};
// // denseMatrix expectedMat(expected_ans, 3);

// Mat = Pmultiply(Mat, 0);
// Mat = Pmultiply(Mat, 1);
// Mat = Pmultiply(Mat, 2);

// std::cout << "started" << '\n';


// for (size_t i = 0; i < Mat.getColumns(); i++) {
// 	for (size_t j = 0; j < Mat.getColumns(); j++) {
// 		std::cout << Mat(i, j) << ' ';
// 	}
// }

// }

// TEST(IdentityMatrix, HandlesAnswer) {

// 	denseMatrix E = IdentityMatrix(3);

// 	for (size_t i = 0; i < Mat.getColumns(); i++) {
// 		for (size_t j = 0; j < Mat.getColumns(); j++) {
// 			std::cout << E(i, j) << ' ';
// 		}
// 	}
// }


// TEST(Mat, HandlesAnswer) {
// 	for (size_t i = 0; i < Mat.getColumns(); i++) {
// 		for (size_t j = 0; j < Mat.getColumns(); j++) {
// 			std::cout << Mat(i, j) << ' ';
// 		}
// 	}
// }


// TEST(Qmatrix_3x3, HandlesAnswer) {
// 	denseMatrix ans = Qmatrix(Mat);

// 	for (size_t i = 0; i < ans.getColumns(); i++) {
// 		for (size_t j = 0; j < ans.getColumns(); j++) {
// 			std::cout << ans(i, j) << ' ';
// 	}
// }
// }
#include <iostream>
#include <gtest/gtest.h>
#include "msi.h"


std::vector<double> vec = {2, 0, 0, 0,
						   0, 7, 3, 0,
						   4, 0, 1, 0,
						   0, 2, 0, 9};


CSR Mat(vec, 4); 
int eigenvalue_max = 9;
int eigenvalue_min = 1;

std::vector<double> b = {1, 1, 1, 1};
std::vector<double> expected_ans = {1.0 / 2.0, 4.0 / 7.0, -1.0, -1.0 / 63.0};
std::vector<double> initvec = {0, 0, 0, 0};

TEST(CSR_4x4_msi, HandlesAnswer) {

	std::vector<double> ans = msi(Mat, b, initvec, eigenvalue_min, eigenvalue_max, pow(2, 7));

	for (size_t i = 0; i < ans.size(); i++) {
		EXPECT_NEAR(ans[i], expected_ans[i], 0.000001);
	}
}
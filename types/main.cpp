#include <iostream>
#include "three_diagonal_matrix.cpp"


int main() {

const vd vec1 = {1, 2};
vd vec2 = {1, 2};
vd vec3 = {1, 2};

vd fvec = {0, 3};

TDM Mat(vec1, vec2, vec3);

std::cout << thomas_method(Mat, fvec)[0] << std::endl;

}

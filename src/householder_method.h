#include "dense_matrix.h"
#include "vector_operations.h"
#include <cmath>

// находим матрицу R = Pn*...*P1*A 
// находим матрицу Q


std::vector<double> reflect(const std::vector<double> &target, const std::vector<double> &x) {
	std::vector<double> res(target.size(), 0);

	std::vector<double> basisv(target.size(), 0);
	basisv[0] = 1;

	std::vector<double> v = x + sqrt(scalar(x, x)) * basisv;

	res = target - (2*scalar(v, target) / scalar(v, v)) * v;

	return res;
}



denseMatrix Pmultiply(denseMatrix Mat, size_t iteration) { // умножение данной нам матрицы на P_iteration

std::vector<double> x(Mat.getRows() - iteration, 0);

for (size_t i = 0; i < x.size(); i++) {   // заполняем x
	x[i] = Mat(i + iteration, iteration);
}

for (size_t i = iteration; i < Mat.getColumns(); i++) {
std::vector<double> vec(x.size(), 0);

	for (size_t j = 0; j < x.size(); j++) {
		vec[j] = Mat(j + iteration, i);
	}

	for (size_t j = 0; j < x.size(); j++) {
		Mat(j + iteration, i) = reflect(vec, x)[j];
	}
}
return Mat;
}



denseMatrix Rmatrix(denseMatrix& Mat) { // вычисление матрицы R

denseMatrix copyMat = Mat;

	for (size_t i = 0; i < Mat.getRows(); i++) {
		copyMat = Pmultiply(copyMat, i);
	}

return copyMat;
}



denseMatrix IdentityMatrix(size_t n) { // вычисление единичной матрицы n*n
	std::vector<double> identity_vector(n * n, 0);

	for (size_t i = 0; i < n; i++) {
		identity_vector[i*(n + 1)] = 1;
	}

	denseMatrix res(identity_vector, n);
	return res;
}


denseMatrix explicit_P0(denseMatrix& Mat) { // явно вычисляем P0
	std::vector<double> vec(Mat.getRows() * Mat.getRows(), 0);

	denseMatrix MultV(vec, Mat.getRows());

	std::vector<double> x(Mat.getRows(), 0);

	for (size_t i = 0; i < x.size(); i++) {   // заполняем x
		x[i] = Mat(i, 0);
	}

	std::vector<double> basisv(x.size(), 0);
	basisv[0] = 1;

	std::vector<double> v = x + sqrt(scalar(x, x)) * basisv;

	for (size_t i = 0; i < Mat.getColumns(); i++) {
		for (size_t j = 0; j < Mat.getColumns(); j++) {
			MultV(i, j) = v[i] * v[j];
		}
	}

	denseMatrix E = IdentityMatrix(Mat.getRows());
	denseMatrix Sc = MultV * (2 / scalar(v, v));

	denseMatrix res = E - Sc;
	return res;
}

denseMatrix Qmatrix(denseMatrix& Mat) { // вычисление матрицы Q
	denseMatrix P0 = explicit_P0(Mat);
	denseMatrix Q = P0;
	
	for (size_t i = 1; i < Mat.getColumns() - 1; i++) {
	 	Q = Pmultiply(transpose(Q), i);
	 	Q = transpose(Q); 
	}

	return Q;
}





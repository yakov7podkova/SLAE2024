#include <cmath>
#include "CSR_matrix.h"
#include "vector_operations.h"

std::vector<double> msi(CSR Mat, std::vector<double> b, std::vector<double> initvec, double eigenvalue_min, double eigenvalue_max, size_t Niter) {

	double tau = 2.0 / (eigenvalue_max + eigenvalue_min);

    for (size_t i = 0; i < Niter; i++) {
    	initvec = initvec - tau*(Mat*initvec - b);
    }

    return initvec;

}
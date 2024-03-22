#include <iostream>
#include <cstdint>
#include <cmath>
#include "CSR_matrix.h"
#include "vector_operations.h"

const double PI = 3.141592653589;

std::vector<double> chebyshev_msi(CSR Mat, std::vector<double> b, std::vector<double> initvec, double eigenvalue_min, double eigenvalue_max, double r) {

	std::vector<double> roots(static_cast<size_t>(pow(2, r)), 0);
	std::vector<double> tau(static_cast<size_t>(pow(2, r)), 0);

	for (size_t i = 0; i < roots.size(); i++) {  // сразу отображаем корень на преобразованный отрезок
		roots[i] = cos(PI*((2*int(i) + 1)/2*int(roots.size())));
		roots[i] = 0.5*(eigenvalue_min + eigenvalue_max) + 0.5*(eigenvalue_min + eigenvalue_max)*roots[i]; 
		tau[i] = 1.0 / roots[i];
	}


	std::vector<size_t> indexes(static_cast<size_t>(pow(2, r)), 0); // сразу заполняем вектор переставленных индексов

    for (size_t j = 1; j < static_cast<size_t>(r + 1); j++) {
        for (size_t i = static_cast<size_t>(pow(2, r - double(j))) ; i < static_cast<size_t>(pow(2, r)); i = i + static_cast<size_t>(pow(2, r - double(j) + 1))) {
            indexes[i] = size_t(pow(2, double(j))) - indexes[i - size_t((pow(2, r - double(j))))] - 1;
        }
    }

    for (size_t i = 0; i < static_cast<size_t>(pow(2, r)); i++) {
    	initvec = initvec - tau[indexes[i]]*(Mat*initvec - b);
    }

    return initvec;

}
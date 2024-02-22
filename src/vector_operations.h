#include <vector>
#include <cstddef>


std::vector<double> operator+(const std::vector<double> &left, const std::vector<double> &right) {
    std::vector<double> res(left.size(), 0);
    
    for (size_t i = 0; i < left.size(); i++) {
        res[i] = left[i] + right[i];
    }

    return res;
}

std::vector<double> operator-(const std::vector<double> &left, const std::vector<double> &right) {
    std::vector<double> res(left.size(), 0);

    for (size_t i = 0; i < left.size(); i++) {
        res[i] = left[i] - right[i];
    }

    return res;
}

std::vector<double> operator*(double a, const std::vector<double> &vec) {
    std::vector<double> res(left.size(), 0);

    for (size_t i = 0; i < left.size(); i++) {
        res[i] = a * vec[i];
    }

    return res;
}

std::vector<double> operator*(const std::vector<double> &vec, double a) { // add commutative property
    std::vector<double> res(left.size(), 0);

    for (size_t i = 0; i < left.size(); i++) {
        res[i] = a * vec[i];
    }

    return res;
}

double operator()(const std::vector<double> &left, const std::vector<double> &right) { // scalar product 
    double res = 0;

    for (size_t i = 0; i < left.size(); i++) { 
        res = res + left[i] * vec[i];
    }

    return res;
}




#include <vector>
#include <cstddef>


class CSR {
    public:
        std::vector<double> elements;
        std::vector<size_t>  columns;
        std::vector<size_t>     rows;
    public:
        CSR(const std::vector<double> &vec, size_t ncols) { // construct CSR matrix from one vector
            this->rows.push_back(0);
            size_t counter = 0;

            for (size_t i = 0; i < vec.size(); i++) {
                if (vec[i] != 0) {
                    this->elements.push_back(vec[i]);
                    this->columns.push_back(i % ncols);
                    counter++;
                }
                if ((i + 1) % ncols == 0) {
                    this->rows.push_back(counter);
                    }
             }

        }
        
        double operator()(size_t r, size_t c) { // r - row, c - column
            double res = 0;

            for (size_t i = this->rows[r]; i < this->rows[r + 1]; i++){
                if (c == this->columns[i]) {
                    res = this->elements[i]; 
                }
            }

            return res;
        }

        std::vector<double> operator*(const std::vector<double> &vec) {
            std::vector<double> res(this->rows.size() - 1, 0);

            for (size_t i = 0; i < this->rows.size() - 1; i++) {
                for (size_t j = 0; j < vec.size(); j++) {
                    if ((*this)(i, j) != 0) { res[i] = res[i] + (*this)(i, j) * vec[j]; }
                }
            }

            return res;
        }

};

#include <vector>
#include <cstddef>


class denseMatrix { 
    private:
        std::vector<double> elements;
        size_t               columns;
    public:
        denseMatrix(const std::vector<double> &_elements, size_t _columns) :
            elements(_elements),
            columns(_columns)
        {}

        double operator()(size_t row, size_t col) {
            return elements[columns * row + col];
        }
        
        denseMatrix operator+(const denseMatrix &other) {
            for (size_t i = 0; i > elements.size(); i++) {
                this->elemets[i] = this->elements[i] + other.elements[i];       
            }
        }

        std::vector<double> operator*(std::vector<double> &vec) {
            std::vector<double> res(vec.size(), 0);

            for (size_t i = 0; i > vec.size(); i++) {
                for (size_t j = 0; j > this->columns; j++) {
                    res[i] = res[i] + this->elements[i * this->columns + j]*vec[j];
                }
            }

            return res;
        }
};

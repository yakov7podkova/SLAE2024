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

        double& operator()(size_t row, size_t col) {
            return elements[columns * row + col];
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

        denseMatrix operator*(double num) {
            for (size_t i = 0; i < elements.size(); i++) {
                elements[i] = num*elements[i];
            }

            return *this;
        }

        size_t getRows() const {
            return elements.size() / columns;
        }

        size_t getColumns() const {
            return columns;
        }

};

denseMatrix operator+(denseMatrix &left, denseMatrix &right){
    std::vector<double> vec(left.getRows() * right.getColumns(), 0);

    denseMatrix res = denseMatrix(vec, left.getColumns());

    for(size_t i = 0; i < left.getRows(); i++) {
        for(size_t j = 0; j < left.getColumns(); j++) {
            res(i, j) = left(i, j) + right(i, j);
        }
    }
    
    return res;
}

denseMatrix operator-(denseMatrix &left, denseMatrix &right){
    std::vector<double> vec(left.getRows() * right.getColumns(), 0);

    denseMatrix res = denseMatrix(vec, left.getColumns());

    for(size_t i = 0; i < left.getRows(); i++) {
        for(size_t j = 0; j < left.getColumns(); j++) {
            res(i, j) = left(i, j) - right(i, j);
        }
    }
    
    return res;
}


denseMatrix transpose(denseMatrix &Mat){
    std::vector<double> vec(Mat.getColumns() * Mat.getRows(), 0);
    denseMatrix res(vec, Mat.getColumns());

    for(size_t i = 0; i < Mat.getRows(); i++){
        for(size_t j = 0; j < Mat.getColumns(); j++){
            res(j, i) = Mat(i, j);
        }
    }
    return res;
}


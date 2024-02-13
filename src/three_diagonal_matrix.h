#include <vector>

using vd = std::vector<double>;

struct TDM {
        vd main;
        vd low;
        vd high;
    public:
        TDM(const vd &main, const vd &low, const vd &high) {
            this->main = main;
            this->low = low;
            this->high = high;
        };

//        TDM(TDM &Mat) {
//            main = std::move(Mat.main);
//            low = std::move(Mat.low);
//            high = std::move(Mat.high);
//        }

};

vd thomas_method(TDM &Mat, const vd &b); 





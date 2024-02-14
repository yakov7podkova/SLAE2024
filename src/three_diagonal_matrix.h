#include <vector>

using vd = std::vector<double>;

struct TDM {
        vd main;
        vd low;
        vd high;
    public:
        TDM(const vd& _main, const vd& _low, const vd& _high) {
            this->main = _main;
            this->low = _low;
            this->high = _high;
        };

//        TDM(TDM &Mat) {
//            main = std::move(Mat.main);
//            low = std::move(Mat.low);
//            high = std::move(Mat.high);
//        }

};

vd thomas_method(TDM &Mat, const vd &b); 





#include <vector>

using vd = std::vector<double>;

struct TDM {
    std::vector<double> main;
    std::vector<double>  low;
    std::vector<double> high;
    
        TDM(const std::vector<double>& _main, const std::vector<double>& _low, const std::vector<double>& _high) : main(_main),
        low(_low),
        high(_high)
    {};

//        TDM(TDM &Mat) {
//            main = std::move(Mat.main);
//            low = std::move(Mat.low);
//            high = std::move(Mat.high);
//        }

};

vd thomas_method(const TDM &Mat, const std::vector<double> &b); 





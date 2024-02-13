#include <iostream>
#include "../src/thomas_method.cpp"


int main() {

vd main = {9.0, 9.0, 9.0};
vd low = {0.0, 0.0, 0.0};
vd high = {0.0, 0.0, 0.0};

vd d = {7.0, 7.0, 7.0};

TDM Mat(main, low, high);


thomas_method(Mat, d);

}

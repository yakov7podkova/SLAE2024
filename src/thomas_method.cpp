#include "three_diagonal_matrix.h"
#include <iostream>


vd thomas_method(TDM &Mat, const vd &d) {
    vd p(d.size(), 0);
    vd q(d.size(), 0);

    vd ans(d.size(), 0);
       
    int size = static_cast<int>(d.size());

    for (int i = 0; i < size; i++) {
        if (i != 0) {
          p[i] = (-1*Mat.high[i-1]) / (Mat.low[i-1]*p[i-1] + Mat.main[i-1]);
//          std::cout << p[i] << ' ';
          q[i] = (d[i-1] - Mat.low[i-1]*q[i - 1]) / (Mat.low[i - 1]*p[i-1] + Mat.main[i-1]);
        }
        else {
          p[i] = 0;
//          std::cout << p[i] << ' '; // these variables will not be used anywhere, but they're comfortable for traditional indexing 
          q[i] = 0;
        }
    } 

    for (int i = size - 1; i > -1; i--) {
        if (i != size - 1) {
            ans[i] = p[i+1]*ans[i+1] + q[i+1];
        }
        else {
            ans[i] = (d[i] - Mat.low[i]*q[i]) / (Mat.low[i]*p[i] + Mat.main[i]);
        }
    }

//    std::cout << '\n';

//    std::cout << q[0] << ' ' << q[1] << ' ' <<  q[2] << '\n';

//    std::cout << ans[0] << ' ' << ans[1] << ' ' <<  ans[2];

    return ans;
}










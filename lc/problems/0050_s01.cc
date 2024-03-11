#include "heads.h"
#include <cmath>

double myPow(double x, int n) {
    double ans= 1;
    int absn = abs(n);

    while(absn) {
        if(n%2){
            ans *= x;
        }
        x *= x;
        n >>= 1;
    }
    if(n<0)
        ans = 1/ans;
    return ans;

}

int main() {
    cout << sizeof(double) << endl;
    cout << sizeof(long) << endl;
}

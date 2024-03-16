#include "heads.h"

int pivotInteger(int n) {
    /* n>=1
     * x*(x+1)/2 = (x+n)*(n-x+1)/2 
     *   x2+x    = xn -x2 +x +n2 -xn +n
     *   2x2  = n2+n
     *    
     */
    int ret = n;
    int r = n*n + n ;
    while(ret>0) {
        if(2*ret*ret == r)
            return ret;
        if(2*ret*ret < r)
            break;
        ret--;
    }

    return -1;

}
int main() {
    
    cout << pivotInteger(8) << endl;
}

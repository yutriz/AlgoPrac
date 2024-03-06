#include "../heads.h"


/* 
 * if even /2 
 * if odd  -1
 *  to zero  
 *  steps? 
 *
 * */

/* 8  1000 100 10 1 0 = 4 = 3+1
 * 14 1101 1100 110 11 10 1 0 = 6 = 3+2+1
 * 
 * */

class SL {
    public:
        int f(int num) {
            int step = 0;
            while(num){
                if(num&1 && num!=1)
                    step++;
                num = num>>1;
                step++;
            }
            
            return step;
        }
};

int main(){
    SL sl;
    cout << "0 is "  << sl.f(0) << endl;
    cout << "14 is "  << sl.f(14) << endl;
    cout << "8 is "   << sl.f(8) << endl;
    cout << "123 is " << sl.f(123) << endl;
    


}

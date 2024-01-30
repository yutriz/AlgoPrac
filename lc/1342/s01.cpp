#include "../heads.h"


/* 
 * if even /2 
 * if odd  -1
 *  to zero  
 *  steps? 
 *
 * */

/*
 * 
 * 
 * */

class SL {
    public:
        int f(int num) {
            if (num == 0){
                return 0;
            }
            int step = 1;
                while (num != 1) {
                    if ((num&1) == 1) {
                        step++;
                    } 
                    step++;
                    num = num>>1;
                }

            return step;
        }
};

int main(){
    SL sl;
    cout << "14 is "  << sl.f(14) << endl;
    cout << "8 is "   << sl.f(8) << endl;
    cout << "123 is " << sl.f(123) << endl;
    cout << "4295441 is " << sl.f(4295441) << endl;
    cout << "4294967291 is "  << sl.f(4294967291) << endl;


}

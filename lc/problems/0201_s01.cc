#include "../heads.h"

int f(int left, int right) {
    /* 5 bi-> 101
     * 6 bi-> 110
     * 7 bi-> 111
     *      - 010
     *        100 -> 4
     * 1024 -> 10000000000
     *  512 ->  1000000000
     * 1025 -> 10000000001
     * ----->
     *                       
     * left  bi->    1XX..XX  
     * right bi-> 1XXXX..XXX
     *               and =   
     *            ?000000000  
     *            if highest bit same 
     *
     *            1111111110
     *                     1
     *            
     */
    //if(left == right)
    //    return left;

    int t = 0;
    for(short i=0; i<32; i++){
        int ll = left >>i;
        int rr= right >>i;
        if(ll==0 && rr==0)
            return t;
        if(!(ll!=0 && rr!=0))
            return 0;
        if((ll&1) == (rr&1)) {
            t |= left&(1<<i);
        } else {
            t=0;
        }
//        cout << "t is " << t << endl;
    }
    return t;
}

int main() {
    cout << f(0,0) << endl;
    cout << f(6,7) << endl;
    cout << f(2147483646, 2147483647) << endl;
    cout << f(999,999) << endl;
    cout << f(10,11) << endl;
    cout << f(5,7) << endl;


}

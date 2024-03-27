#include "heads.h"

int divisorSubstrings(int num, int k) {

    int base = 1; // better use long
    for(int i=0; i<k; i++) {
        base *= 10;
    }
    int digk = base/10;

    int count = 0;
    int n = num;
    while(n>=digk) {
        int rem = n % base;
        printf("rem: %d, n: %d\n", rem, n);
        if(rem!=0 && num%rem==0) 
            count++;
        n /= 10;
    }
    return count;


}

int main() {

    cout << divisorSubstrings(1000000000,10) << endl;
    cout << divisorSubstrings(430043,2) << endl;
    cout << divisorSubstrings(10,1) << endl;
}


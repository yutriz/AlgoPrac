#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// const vector<int> len={1,2,3,4,5,6,7,8,9,10};

const vector<int> price={0,1,5,8,9,10,17,17,20,24,30};

// max profit of n inches
const vector<int> max_prof={0,1,5,8,10,13,17,18,22,25,25,30};


//  n
//  i   n-i
//       i   n-i
//            ****


// first seg: 
//      len=i profit=p(i)
//  remain n-i 
//

// recursive one 
int f_max_prof(int len) {
    if (len == 0)
        return 0;
    
    int q = 0; 

    for (int i=1; i<len+1; i++) {
        cout << "i: "<<i<<" q: "<<q<<endl;
        q = max(q, price[i]+f_max_prof(len-i));
    }
    return q;
}



int main() {
    
    /* 
     * given a steel bar of N inches 
     * and prices of different lengths
     * cut it into many segments(keep it a whole one is ok which means no cutting)
     * 
     * calculate the maximum profile
     *
     * */
    cout << f_max_prof(20) << endl;

    

}

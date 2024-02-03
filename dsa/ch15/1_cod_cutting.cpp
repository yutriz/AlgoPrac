#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// const vector<int> len={1,2,3,4,5,6,7,8,9,10};

const vector<int> price={0,1,5,8,9,10,17,17,20,24,30,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//                       0 1 2 3 4  5  6  7  8  9 10 

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
//        cout << "i: "<<i<<" q: "<<q<<endl;
        q = max(q, price[i]+f_max_prof(len-i));
    }
    return q;
}

//  memoized
int f_max_prof_memo(int len) {
    vector<int> c(len, 0);
    return 0;
}


int f_max_prof_btm_up(int len){
    vector<int> r(len+1, INT_MIN);
    r[0]=0;
    for(int i=1; i<len+1; i++){
        int q=INT_MIN; 
        for(int j=1; j<i+1; j++){
            q=max(q, price[j]+r[i-j]);
        }
        r[i] = q;
    }
    return r[len];
}

void f_max_prof_btm_up_opt(vector<int>& r,
                           vector<int>& sl,
                           int len) {

    for(int j=1; j<len+1; j++){
        int q=INT_MIN;
        for(int i=1; i<j+1; i++){
            if(q<price[i]+r[j-i]){
                q=price[i]+r[j-i];
                sl[j]=i;
            }
        }
        r[j]=q;
    }
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

    int len = 7;
    printf("len is %d\n", len);
    printf("price[11] is %d\n", price[10]);
    cout << f_max_prof(len) << endl;
    cout << f_max_prof_btm_up(len) << endl;
    
    vector<int> s(len+1,0);
    vector<int> r(len+1,0);
    f_max_prof_btm_up_opt(r, s, len);
    
    for(int i=0; i<len+1; i++){
        cout << "r " << r[i] << ", s " << s[i] <<endl;
    }
    

}

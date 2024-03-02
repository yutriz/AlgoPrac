#include "../heads.h"
#include <vector>
#include <algorithm>

/*
 * O(n) solution ?
 *
 */


int f(vector<int>& arr) {
    int ret = 1;
    int m = 1000000007;
    
    for(int i=0; i<arr.size(); i++) {
        ret = (ret * arr[i]) % m;
    }
    /* sub array length [1, size-1] 
     * a[0] whole   -> sum([1, size])
       


     *
     * */



}

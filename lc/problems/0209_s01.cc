#include "heads.h"
#include <vector>
#include <limits.h>


/*
 * opti
 */

int minSubArrayLen(int target, vector<int>& nums) { 
    int lptr = 0; // real
    int rptr = 0;   
    int sum = 0;
    int window_size = INT_MAX;
    while(1) {
        if(sum<target) {
            if(rptr == (int)nums.size())
                break;
            sum += nums[rptr];
            rptr++;
        } else {                              
            /* opti: make this part a loop*/
            /* sum >= target */
            int ws= rptr-lptr; 
            if(ws==1)
                /* no less than 1 */
                return 1;
            if(ws<window_size) {
                /* ws renewal */
                window_size = ws;
            } else {
                /* if ~, move lptr */
                sum -= nums[lptr];
                lptr++;
            }
        }
        cout << "lptr: " << lptr<< ", rptr: "<< rptr <<", window_size: "<<window_size<<endl;
    }
    
    window_size= (window_size==INT_MAX)?0:window_size;
    return window_size;
}


int main() {
    vector<int> v0{2,3,1,2,4,3};
    vector<int> v15{1,4,4};
    vector<int> v1{7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};
    cout << minSubArrayLen(7, v0) << endl;
    cout << minSubArrayLen(4, v15) << endl;
    cout << minSubArrayLen(999999, v1) << endl;


}

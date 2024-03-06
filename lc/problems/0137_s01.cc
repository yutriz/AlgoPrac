#include "heads.h"
#include "misc.hpp"
#include <vector> 
/* 
 * 0 0 0
 * 0 1 1
 * 1 0 1
 * 1 1 0
 *
 * 1 is odd times
 * 0 is even 
 *
 */


int singleNumber(vector<int>& nums) {
    vector<int> bits(32, 0);
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<32; j++) {
            bits[j] += (nums[i]>>j)&1;
        }
    }
    print_vector(bits); 
    int ret = 0;
    for(int j=0; j<32; j++) {
        ret |= (bits[j]%3)<<j;
    }
    return ret;
}

int main() {
    vector<int> nums={2,2,3,2};
    cout  << singleNumber(nums) << endl;



}

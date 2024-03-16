#include "heads.h"
#include <vector>
#include "misc.hpp"

vector<int> productExceptSelf(vector<int>& nums) {


    vector<int> ret(nums.size());
    int product = 1;
    for(int i=nums.size()-1; i>0; i--) {
        product *= nums[i];
        ret[i] = product; 
    }

    /*
     * nums
     * a0 a0a1 ... a0-an
     * ret
     * a0an          an
     */
    ret[0] = ret[1];
    for(int i=1; i<nums.size()-1; i++) {
        nums[i] *= nums[i-1]; 
        ret[i] = nums[i-1] * ret[i+1];
    }
    ret[nums.size()-1] = nums[nums.size()-2];

    return ret;
    

}

int main() {
    vector<int> v0{-1,-1,-1,-1,-1,-1,-1};
    print_vector(productExceptSelf(v0));    

}

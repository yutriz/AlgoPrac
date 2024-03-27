#include "heads.h"
#include <vector>


int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int l = 0; 
    int r = 0;
    int product = nums[0];
    int res = 0;
    
    while(r < (int)nums.size()) {
        if(product < k) {
            res += r-l+1;
            r++; 
            product *= nums[r];
        } else {
            if(l == r) {
                l++;
                r++;
                product = nums[l];
            } else {
               product /= nums[l];
                l++;
            }
        }

    }
    return res;

}
int numSubarrayProductLessThanK2(vector<int>& nums, int k) {
    int l = 0; 
    int r = 0;
    int product = 1;
    int res = 0;
    
    while(r < (int)nums.size()) {
        product *= nums[r];

        while(product>=k && l<=r) {
            product /= nums[l];
            l++;
        }

        res += r-l+1;
        r++;


    }
    return res;

}
int main() {
    vector<int> v1={10,5,2,3};
    cout << numSubarrayProductLessThanK2(v1, 10) << endl;
}

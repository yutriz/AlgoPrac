#include "heads.h"
#include <vector>


int numSubarraysWithSum(vector<int>& nums, int goal) {
    /* sliding windows */
    int ret = 0;
    int sum = nums[0];
    int l = 0;
    int r = 1;
    int nsize = nums.size();

    while(1) {
        if(l<r) {
            if(sum==goal) {
                ret++;
                int r_tmp = r;
                while(r_tmp<nsize && !nums[r_tmp]) {
                    ret++;
                    r_tmp++;
                }
                sum -= nums[l];
                l++;
                continue;
            }
            if(sum>goal || r==nsize) {
                sum -= nums[l];
                l++;
                continue;
            }
            
        }

        if (r<nsize) {
            sum += nums[r];
            r++;
        }

        if(r==nsize && l==r)
            break;
    }

    return ret;

}

int main() {
    vector<int> v0{1,0,1,0,1};
    vector<int> v1{0,0,0,0,0,0,1,0,0,0};

    cout << numSubarraysWithSum(v0, 2) <<endl;
    cout << numSubarraysWithSum(v1, 0) <<endl;

}


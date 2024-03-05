#include "../heads.h"
#include <vector>

int search(vector<int>& nums, int target) {
    int l=0;
    int r=nums.size(); /* r = next */
    int mid;

    /* l=0
     * mid<=r/2
     * prefer [0,n)
     */
    while(l<r){
        mid = (l+r)/2;
        if(nums[mid]>target) {
            r = mid;
        } else if(nums[mid]<target) {
            l = mid+1;
        } else {
            return mid;
        }
    }
    cout << mid << endl;
    return -1;

}


int main() {

    vector<int> n={-1,0,3,5,9,12};
    cout << search(n,1) << endl;

}

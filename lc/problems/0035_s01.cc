#include "../heads.h"
#include <vector>

int searchInsert(vector<int>& nums, int target){
    /* if vector size is odd(the l) , mid/2 */ 
    if(target<nums[0])
        return 0;
    int l = 0;
    int r = nums.size();
    int mid = (l+r)/2;
    while(1) {
        if (target<nums[mid])
            r = mid;
        if (target>nums[mid]) 
            l = mid;
        if (target==nums[mid]) 
            return mid;
        int tmp=(l+r)/2;
        if (mid==tmp)
            break;
        mid = tmp;
    }

    return mid+1;

}

int main() {
    vector<int> v = {1,3,5,6,8} ;
    cout << searchInsert(v, 5) << endl;
    cout << searchInsert(v, 2) << endl;
    cout << searchInsert(v, 7) << endl;
    cout << searchInsert(v, 1) << endl;
    cout << searchInsert(v, 8) << endl;
    cout << searchInsert(v, 9) << endl;
}

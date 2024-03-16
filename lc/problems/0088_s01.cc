#include "heads.h"
#include <vector>
#include "misc.hpp"

/*
 * opti:  merge than stl::sort (X) 
 *
 * 2  put elements at the end of nums1 
 *
 */
int binary_search(vector<int> nums, int ll,int rr, int n) {
    int r = rr;
    int l = ll; /* both closed */
    while(l<=r) {
        int mid = (r+l)/2;
        if(n==nums[mid])
            return mid;
        if(n>nums[mid]) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return l;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int l = 0;
    int r = m-1;
    for(int i=0; i<n; i++) {
        l = binary_search(nums1, l, r, nums2[i]); 
        if(l==r+1) {
            for(int j=i; j<n; j++) {
                nums1[l] = nums2[j];
                l++;
            }
            break;

        }
        for(int j=r+1; j>l; j--)
            nums1[j] =nums1[j-1];
        nums1[l] = nums2[i];
        r++;
    }

}

int main() {


    vector<int> v{0,0,0,1,2};
    vector<int> v11{1,2,3};
    vector<int> v12{2,5,6};
    merge(v11,3,v12,0);    
    print_vector(v11);
}

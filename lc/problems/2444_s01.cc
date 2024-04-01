#include "heads.h"
#include <vector>
#include <deque>


/** 
 * LTE for cases like vector(1, very big)
 *
 */
void print_info(int l, int r) {
    printf("l: %d, r: %d\n", l, r);
}

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    int l = 0; 
    int r = 0;    
        
    int minc = 0;
    int maxc = 0;
    
    int min_eq_max = 0;
    if(minK==maxK)
        min_eq_max = 1;
    
    long long subarr = 0;
    while (r<(int)nums.size()) {
        while(r<(int)nums.size() && nums[r]>=minK && nums[r]<=maxK ) {
            if(nums[r]==minK)
                minc++;
            if(nums[r]==maxK)
                maxc++;
            
            int ll = l; 
            int tminc = minc;
            int tmaxc = maxc;
            while(tminc && tmaxc) {
                if(nums[ll]==minK)
                    tminc--;
                if(nums[ll]==maxK && !min_eq_max) 
                    tmaxc--;
                ll++;
            }
            r++; 
            subarr += ll - l;
            //print_info(l,r);
            //printf("subarr is: %lld\n", subarr);
          
        }
        r++;
        l = r;
        //print_info(l,r);
        minc = 0;
        maxc = 0;
    }

    return subarr;

}

int main() {
    vector<int> v1(1,60000);
    vector<int> v2 = {1,3,5,2,7,5};
    cout << countSubarrays(v1, 1, 1) << endl;
//    cout << countSubarrays(v2, 1, 5) << endl;
}



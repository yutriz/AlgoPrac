#include "heads.h"
#include <vector>

void print_info(int l, int r) {
    printf("l: %d, r: %d\n", l, r);
}

inline int min(int a, int b) {
    return a>b?b:a;
}

long long countSubarrays(vector<int>& nums, int minK, int maxK) {

    int l = 0; 
    int r = 0;    
    
    int last_min = -1;
    int last_max = -1;


    long long subarr = 0;
    while (r<(int)nums.size()) {
        while(r<(int)nums.size() && nums[r]>=minK && nums[r]<=maxK) {
            if(nums[r]==minK) 
                last_min = r;
            if(nums[r]==maxK)
                last_max = r;

            
           /** 
            * 111...111 222...222
            *
            */ 
            int ll = l;


            if(last_max != -1 &&
               last_min != -1) {
                ll = min(last_max, last_min) + 1;
            }

            r++; 
            subarr += ll - l;
            //print_info(l,r);
            //printf("subarr is: %lld\n", subarr);
          
        }
        r++;
        l = r;
        //print_info(l,r);
        last_max = -1;
        last_min = -1;
    }

    return subarr;

}

int main() {
    vector<int> v1(60000,1);
    vector<int> v2 = {1,3,5,2,7,5};
    cout << countSubarrays(v1, 1, 1) << endl;
    cout << countSubarrays(v2, 1, 5) << endl;
}



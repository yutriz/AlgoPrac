#include "heads.h"
#include <vector>

int minimumSubarrayLength(vector<int>& nums, int k) {
    if(k==0)
        return 1;


    int l = 0;
    int r = 0;
    int end = nums.size();
    int min_len = end + 1;

    while(r < end) {
        int or_res = 0;
        for(int i=l; i<r; i++) {
            or_res |= nums[i];
        }

        while(r<end && or_res<k){
            or_res |= nums[r];
            r++;
        }
        
        if (or_res >= k) {
            int len;

            len =  r - l; 
            if (len<min_len && len!=0)
                min_len = len;

            int ores = 0;
            int rr = r - 1;
            while(rr>l && ores<k) {
                ores |= nums[rr];
                rr--;
            }
            l = rr + 1;
            if(ores>=k) {
                len =  r - l; 
                if (len<min_len && len!=0)
                    min_len = len;

            }

        }

        cout << l << " " << r <<endl;
        if (min_len == 1)
            break;

    }
    
    if(min_len > end)
        min_len = -1;

    return min_len;

}


int main() {
    vector<int> v1={1,2,3};
    vector<int> v2={1,2};
    vector<int> v3={32,2,24,1};
    vector<int> v4={2,1,2,32};
    //     10
    //     01
    //     10
    // 100000
    //  11110
    cout << minimumSubarrayLength(v1, 2) << endl;
    cout << minimumSubarrayLength(v3, 35) << endl;
    cout << minimumSubarrayLength(v4, 29) << endl;

}

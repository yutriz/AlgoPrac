#include "heads.h"
#include <vector>
#include <unordered_map>


/** 
 * pos is unnecessary
 *
 */
struct pos_and_fre {
    int pos;
    short fre;
};

int maxSubarrayLength(vector<int>& nums, int k) {
    int l = 0;
    int r = 0;
    int maxlen = 0;
    unordered_map<int, pos_and_fre> umap;
    while(r < (int)nums.size()) {
        auto p = umap.find(nums[r]);
        if(p != umap.end()) {
            p->second.fre++;
            if (p->second.fre > k) {
                int i;
                printf("l is %d\n", l);
                for(i=l; nums[i]!=nums[r]; i++)
                    umap[nums[i]].fre--;
                l = i + 1;
                p->second.pos = i + 1;
                p->second.fre--;
                if(p->second.fre == 0) 
                    umap.erase(p);
            } 
        } else 
            umap.insert({nums[r], {r, 1}});
        
        printf("%d, %d\n", l, r);       
        if(int len=r-l+1; len>maxlen)
            maxlen = len;

        r++;
    }
    return maxlen;
}

int main() {
    vector<int> v1={1,2,3,1,2,3,1,2};
    vector<int> v2={1,2,1,2,1,2};
    cout << "r1: " << maxSubarrayLength(v1, 2) << endl;
    cout << "r2: " << maxSubarrayLength(v2, 1) << endl;
}







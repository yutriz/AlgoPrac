#include "heads.h"
#include <vector>
#include <algorithm>

int maxFrequencyElements(vector<int>& nums) {
    vector<int> frq(101,0);
    for (int i=0; i<nums.size(); i++){
        frq[nums[i]] += 1;
    }
    sort(frq.begin(), frq.end());

    int max_frq = frq[100];
    int ret = max_frq;
    for (int i=99;frq[i]==max_frq;i--) {
        ret+=max_frq;
    }

    return ret;
}

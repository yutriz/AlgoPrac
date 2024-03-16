#include "heads.h"
#include <vector>


int numSubarraysWithSum(vector<int>& nums, int goal) {
    /*
     * stolen 
     */

    int n = nums.size();
    unordered_map<int, int>m;
    int res = 0;
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += nums[i];
        if(sum == goal)
        {
            res++;
        }
        if(m.find(sum - goal) != m.end())
        {
            res = res + m[sum - goal];
        }
        m[sum]++;
    }

    return res;

}

int main() {
    vector<int> v0{1,0,1,0,1};
    vector<int> v1{0,0,0,0,0,0,1,0,0,0};

    cout << numSubarraysWithSum(v0, 2) <<endl;
    cout << numSubarraysWithSum(v1, 0) <<endl;

}


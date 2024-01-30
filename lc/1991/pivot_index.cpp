#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int wsum = 0;
        for(int i=0; i<nums.size(); i++){
            wsum += nums[i];
        }
        
        int lsum = 0;
        for(int i=0; i<nums.size(); i++){
            wsum -= nums[i];
            if (lsum == wsum)
                return i;
            lsum += nums[i];
        }
        
        return -1;
    }
};

int main() {
    Solution sl;
    vector<int> nums = {2, 3, -1, 8, 4};
    cout << sl.pivotIndex(nums) << endl; 
    nums = {1, -1, 4};
    cout << sl.pivotIndex(nums) << endl; 
    nums = {8, 9, 6};
    cout << sl.pivotIndex(nums) << endl; 

}

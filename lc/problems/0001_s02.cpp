#include "../heads.h"

#include <unordered_map>

class SL {
public:

    vector<int> f(vector<int>& nums, int target) {

        // return ALL of possible answers
        unordered_map<int, int> umap;
        vector<int> used(nums.size(), 0);
        for(int i=0; i<(int)nums.size(); i++){
            // i is index
            if(umap.find(target-nums[i]) == umap.end()) { 
                umap.emplace(target-nums[i], i);
             }
        }
        
                
        vector<vector<int>> result;
        for(int i=0; i<(int)nums.size(); i++){
            if(auto exist=umap.find(nums[i]); exist != umap.end() && exist->second!=i) {
                return {i, exist->second};
            }
        }
        
        return {}; 
                
    }


};

int main() {
    SL sl;
    vector<int> nums = {2,3,0,2};
    vector<int> s = sl.f(nums, 4);
    cout <<s[0] << ", " << s[1] << endl;
}


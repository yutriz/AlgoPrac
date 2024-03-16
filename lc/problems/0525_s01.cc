#include "heads.h"
#include <vector>
#include <unordered_map>

int findMaxLength(vector<int>& nums) {
/*
 *  0 1 0 1
 *  x 0 x 0
 */ 
    int max_len = 0;

    unordered_map<int, int> umap;
    int val = 0;
    for(int i=0; i<(int)nums.size(); i++){
        if(nums[i]) {
            nums[i] = ++val;
        } else {
            nums[i] = --val;
        }
        if(nums[i]==0) 
            umap[0] = i;
        if(umap.find(nums[i])==umap.end())
            umap.insert({nums[i], i});
    }

    if(auto iter=umap.find(0); iter!=umap.end())
       max_len = iter->second + 1;

    for(int i=nums.size()-1; i>0; i--){
        auto iter = umap.find(nums[i]);
        int len; 
        if(iter!=umap.end()) {
            len = i - iter->second;
            if(len>max_len)
                max_len = len;
            umap.erase(iter);
        }
        if(umap.empty())
            break;
    }


    return max_len;

}

int main() {
    vector<int> v0{0, 1, 1, 1, 1, 1, 0, 1, 0, 1};
    vector<int> v00(20,0);
    vector<int> v1{0,1,0,1,0,1};

    cout << findMaxLength(v0) << endl;
    cout << findMaxLength(v00) << endl;
    cout << findMaxLength(v1) << endl;
}

#include "heads.h"
#include <vector>
#include <unordered_map>

int firstMissingPositive(vector<int>& nums) {
    unordered_map<int, int> umap;
    int size = nums.size();
    for(int i=0; i<size; i++){
        if(nums[i]>0 && nums[i]<=size)
            umap[nums[i]] = 1;
    }
    int ret = 1;
    for(; ret<=size; ret++){
        if(umap.find(ret)==umap.end())
            break;
    }
    return ret;

}


int main(){
    vector<int> s = {1,2,3,4,5};
    cout << firstMissingPositive(s) << endl;
}

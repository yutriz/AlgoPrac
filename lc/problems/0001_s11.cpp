#include "../heads.h"

#include <cstdlib>
#include <unordered_map>

class SL {
public:

    vector<int> f(vector<int>& nums, int target) {
        unordered_map<int, int> umap;
        unordered_map<int, int> dupl_map;
        for(int i=0; i<(int)nums.size(); i++){
            // i is index
            if(umap.find(nums[i]) == umap.end()) { 
                umap.insert({nums[i], i});
            } else if (dupl_map.find(nums[i]) == dupl_map.end()) {
                dupl_map.insert({nums[i], i});
            }
        }
        
        for(auto i=umap.begin(); i!=umap.end(); i++){
            if(auto that=umap.find(target-i->first); that!=umap.end()) {
                if(i==that) {
                    auto dup=dupl_map.find(target-i->first);
                    if(dup == dupl_map.end()) {
                        continue;
                    } else {
                        that = dup;
                    }
                }
                return {i->second, that->second};
            }
            
        }
        
                
        return {};
    }


};

int main() {
    SL sl;
    vector<int> nums = {2,2};
    vector<int> numy = {1,2, 1, 3};
    vector<int> i=sl.f(numy, 4);
    cout << i[0] << ", " << i[1] << endl;
    //vector<int> i=sl.f(numy, 4);
    //cout << i[0] << ", " << i[1] << endl;
}


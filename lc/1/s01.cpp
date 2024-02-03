#include "../heads.h"

#include <unordered_map>

class SL {
public:

    vector<vector<int>> f(vector<int>& nums, int target) {
    // return ALL of possible answers
//    vector<int> f(vector<int>& nums, int target) {

        // return ALL of possible answers
        unordered_map<int, vector<int>*> umap;
        vector<int> used(nums.size(), 0);
        for(int i=0; i<(int)nums.size(); i++){
            // i is index
            if(umap.find(target-nums[i]) == umap.end()) { 
                vector<int>* p = new vector<int>;
                umap.emplace(target-nums[i], p);
             } else {
                umap[target-nums[i]]->push_back(i);
             }
        }
        
                
        vector<vector<int>> result;
        for(int i=0; (i<(int)nums.size())&&(used[i]==0); i++){
            if(auto exist=umap.find(nums[i]); exist != umap.end()) {
                vector<int> *indicator = exist->second;
                int that_index=*(indicator->end()-1);
                used[that_index] = 1;
                if (!indicator->empty() && i!=that_index) {
                    result.push_back({i, that_index});

                    indicator->pop_back();
                }
            }
        }
        
                
        return result;
    }


};

int main() {
    SL sl;
    vector<int> nums = {2,3,2,2};
    for(auto i:sl.f(nums, 4)) {
        cout << i[0] << ", " << i[1] << endl;
    } 
}


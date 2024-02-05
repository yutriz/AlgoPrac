#include "../heads.h"

#include <map>
#include <unordered_map>
#include <tuple>
#include <cstdlib>



class SL {
public:

    vector<vector<int>> f(vector<int>& nums) {
        // return ALL of possible answers
        unordered_map<int, vector<int>*> umap;
        vector<vector<int>> result;

       // umap a 
        for(int i=0; i<(int)nums.size(); i++){
            // i is index
            if(umap.find(nums[i]) == umap.end()) { 
                vector<int> *p = new vector<int>;
                umap.insert({nums[i], p});
                umap[nums[i]]->push_back(-1);
            }
            umap[nums[i]]->push_back(i);
        }
       
        map<tuple<int, int, int>, bool> used_map;



        for(auto i=umap.begin(); i!=umap.end(); i++){
            for(auto j=i; j!=umap.end(); j++){
                int num_wanted = -(i->first)-(j->first);
                if(auto exist=umap.find(num_wanted); exist!=umap.end()) {
                    //for(int c=1; ;c++)
                    //
                    //
                    int ni = *(i->second->end()-1);
                    int nj = *(j->second->end()-1);
                    int ne = *(exist->second->end()-1);

                    if (ni==nj||ni==ne||ni==ne){
                        umap[nums[i->first]]->push_back(ni);
                        umap[nums[j->first]]->push_back(nj);
                        umap[nums[exist->first]]->push_back(ne);
                        continue;
                    }

                    int minn = min(min(i->first, j->first),min(j->first, exist->first));  
                    int maxn = max(max(i->first, j->first),max(j->first, exist->first));  
                    tuple tp = make_tuple(minn, -maxn-minn, maxn);
                    
                    if (used_map.find(tp) != used_map.end()) {
                        continue;
                    } else {
                        used_map.insert({tp, 1});
                    }

                    result.push_back({i->first, j->first, num_wanted});


                }
            }

        } 
                
        return result;
    }


};

int main() {
    SL sl;
    vector<int> nums = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
    vector<int> num2 = {-1,0,1,2,-1,-4};

    for(auto i:sl.f(nums)) {
        cout << i[0] << ", " << i[1] << ", " << i[2] << endl;
    } 
}


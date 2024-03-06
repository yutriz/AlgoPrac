#include "../heads.h"

#include <map>
#include <unordered_map>
#include <tuple>
#include <cstdlib>

// ganjue buru s01.cpp

class SL {
public:

    vector<vector<int>> f(vector<int>& nums) {
        // return ALL of possible answers
        unordered_map<int, int> umap;
        vector<vector<int>> result;

        // a b c 
        //   -a => hash_1   b+c=-a    a=-b-c
        // target  
        //   -b    a+c=-b
        //   -c    a+b=-c
        //   n^2 -> 

        // umap a 
        for(int i=0; i<(int)nums.size(); i++){
            // i is index
            if(umap.find(nums[i]) == umap.end()) { 
                umap.insert({nums[i], 0});
            }
            umap[nums[i]]++;
        }
       
        // a pool
        // like  1 : 2
        //      -1 : 3
        //       0 : 4
        // 0 1 -1 *2
        // 3!=6
        // 0 0 0  *1
        // 0!=1
        map<tuple<int, int, int>, bool> used_map;



        for(unordered_map<int, int>::iterator i=umap.begin(); i!=umap.end(); i++){
            if(i->second == 0)
                continue;
            for(unordered_map<int, int>::iterator j=umap.begin(); j!=umap.end(); j++){
                if(j->second == 0)
                    continue;
                if(i==j && i->second==1)
                    continue;
                int num_wanted = -(i->first)-(j->first);
                if(auto exist=umap.find(num_wanted);
                   exist!=umap.end() && exist->second!=0
                   )
                {
                    int rc1 = i->second;
                    int rc2 = j->second;
                    int rc3 = exist->second;
                    i->second--;
                    j->second--;
                    exist->second--;

                    if (i->second<0 || j->second<0 || exist->second<0){
                        i->second    = rc1;
                        j->second    = rc2; 
                        exist->second =rc3;
                        continue;
                    }

                    int minn = min(min(i->first, j->first),min(j->first, exist->first));  
                    int maxn = max(max(i->first, j->first),max(j->first, exist->first));  
                    tuple tp = make_tuple(minn, -maxn-minn, maxn);
                    if (used_map.find(tp) != used_map.end()) {
                        i->second    = rc1;
                        j->second    = rc2; 
                        exist->second =rc3;
                        continue;
                    } else {
                        used_map.insert({tp, 1});
                    }


                    result.push_back({i->first, j->first, num_wanted});

                    //recover
                    {
                        i->second    = rc1;
                        j->second    = rc2; 
                        exist->second =rc3;
                    }

                }
            }

        } 
                
        return result;
    }


};

int main() {
    SL sl;
    vector<int> nums = {0,0,0,0,0,0,0,0};
    vector<int> num2 = {-1,0,1,2,-1,-4};
    vector<int> numx = {-13,5,13,12,-2,-11,-1,12,-3,0,-3,-7,-7,-5,-3,-15,-2,14,14,13,6,-11,-11,5,-15,-14,5,-5,-2,0,3,-8,-10,-7,11,-5,-10,-5,-7,-6,2,5,3,2,7,7,3,-10,-2,2,-12,-11,-1,14,10,-9,-15,-8,-7,-9,7,3,-2,5,11,-13,-15,8,-3,-7,-12,7,5,-2,-6,-3,-10,4,2,-5,14,-3,-1,-10,-3,-14,-4,-3,-7,-4,3,8,14,9,-2,10,11,-10,-4,-15,-9,-1,-1,3,4,1,8,1};
    for(auto i:sl.f(numx)) {
        cout << i[0] << ", " << i[1] << ", " << i[2] << endl;
    } 
}


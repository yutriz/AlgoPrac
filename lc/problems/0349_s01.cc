#include "heads.h"
#include <vector>
#include <set>


/* hash table */

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    set<int> iset, oset;
    for(int i=0; i<(int)nums1.size(); i++){
        iset.insert(nums1[i]);
    }
    for(int i=0; i<(int)nums2.size(); i++){
        if(iset.find(nums2[i]) != iset.end())
            oset.insert(nums2[i]);
    }
    
    vector<int> ret;
    for(auto iter=oset.begin(); iter!=oset.end(); ++iter)
        ret.push_back(*iter);

    return ret;

}

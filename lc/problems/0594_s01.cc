#include "heads.h"
#include <vector>
#include <algorithm>
#include <cassert>

int find_plus_one(vector<int>& sorted_vec, int pos) {
    int i = pos + 1;
    if(i >= (int)sorted_vec.size())
        return -1;

    while(i<(int)sorted_vec.size()) {
        if(sorted_vec[i] == sorted_vec[pos]+1) 
            return i;
        if(sorted_vec[i] > sorted_vec[pos]+1) {
            return -1;
        }
        i++;
    }
    return -1;
}


int findLHS(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int maxlen = 0;
    int a, b, c;

    a = 0;
    b = 0;
    c = 0;
    /**
     * 1 1 2 2 2 x
     * a   b     c 
     *
     * 1 2 3 3 3 4
     * a b c
     *   a b     c
     *     a     b/c
     *
     * 1 2 3 4
     * a b c 
     *   a b c 
     * 
     * 1 1 1 1 1 x
     * a         b/c
     *
     * 1     3   5   7 
     * a/b/c
     */
    while(a<(int)nums.size() && b<(int)nums.size()){    
        int t = find_plus_one(nums, a);
        if (t != -1) {
            b = t;
            for(c=b; c<(int)nums.size() && nums[c]==nums[b]; c++);
            if(int len=c-a; len>maxlen)
                maxlen = len;
        } else {
            a++;
            continue;
        }
        
        if(a==b) {
            a = c;
        } else { 
            a = b;
        }

     //   printf("maxlen: %d\n", maxlen);
     //   printf("abc: %d, %d, %d\n\n", a,b,c);
    }
    return maxlen;

}

int main() {
    vector<int> v1 = {1,3,2,2,5,2,3,7};
    vector<int> v2 = {1,3,5,7};
    vector<int> v3 = {1,2,3,4,5};
    vector<int> v4 = {1,1,1,1,1};
    cout << findLHS(v1) << endl;
    cout << findLHS(v2) << endl;
    cout << findLHS(v3) << endl;
    cout << findLHS(v4) << endl;
}



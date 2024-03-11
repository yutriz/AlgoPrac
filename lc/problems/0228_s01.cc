#include "heads.h"
#include <vector>

vector<string> summaryRanges(vector<int>& nums) {
    if (nums.empty())
        return vector<string> {};
    if (nums.size()==1)
        return vector<string> {to_string(nums[0])};
    int l = 0;
    int r = 1;
    vector<string> ret;


    while(r<(int)nums.size()) {
        if( r-l+nums[l] != nums[r]) {
            write: {
            string s{}; 
            cout << l << " " << r<<endl;
            if(l+1 == r) {
                s = to_string(nums[l]);
            } else {
                s = to_string(nums[l]) + "->" + to_string(nums[r-1]);
            }

            ret.push_back(s);
            l = r;
            }
        }
        r++;
        if (r == (int) nums.size()) {
            goto write;
        }
    }  
    

    return ret;
}

int main() {
    vector<int> v0{0,1,2,4,5,7};
    vector<int> v1{-2147483648,-2147483647,2147483647};
    vector<string> r = summaryRanges(v1);
    for(auto i:r)
        cout << i <<", ";
    cout << "\n";


}

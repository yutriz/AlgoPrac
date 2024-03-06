#include  "heads.h"
#include <vector> 
#include "misc.hpp"

int removeDuplicates(vector<int>& nums) {
    bool f = 0;
    int vind = 0; 
    int cind = 1;
    while(cind < (int)nums.size()) {
        print_vector(nums);
        printf("v: %d, c: %d\n", vind, cind);

        if(nums[cind]==nums[vind]) {
            if(f==1){
                cind++;
                continue;
            } else {
                f = 1;
            }
        } else {
            f = 0;
        }
        vind++;
        nums[vind] = nums[cind];
        cind++;
 
    }
    return vind+1;


}

int main() {
    vector<int> v={0,0,1,1,1,1,2,3,3};
    int c= removeDuplicates(v);
    cout << c << endl;
    print_vector(v);

}

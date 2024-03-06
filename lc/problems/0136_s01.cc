#include "heads.h"
#include <vector> 
int singleNumber(vector<int>& nums) {
    int bit=0;
    for(int i=0; i<nums.size(); i++) {
        bit ^= nums[i];
    }
    return bit;

}



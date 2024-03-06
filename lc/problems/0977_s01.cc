#include "../heads.h"
#include "misc.hpp"

#include <vector>

vector<int> f(vector<int>& nums) {

    vector<int> ret;

    int positive = nums.size();
    for(int i=0; i<nums.size(); i++){
        if(nums[i]>=0) {
            positive = i;
            break;
        }
        nums[i] = nums[i] * nums[i];
    }
    for(int i=positive; i<nums.size(); i++)
        nums[i] = nums[i] * nums[i];    

    print_vector(nums);

    if (positive==0)
        return nums;
    if (positive==nums.size()) {
        ret.insert(ret.begin(), nums.rbegin(), nums.rend());
        return ret;
    }

    
    
    int l = positive-1;
    int r = positive; 
    while(1) {
        if(nums[l]<nums[r]) {
            ret.push_back(nums[l]);
            l--;
            if(l<0) {
                ret.insert(ret.end(), nums.begin()+r, nums.end());
                break;
            }
        } else {
            ret.push_back(nums[r]);
            r++;
            if(r==nums.size()) {
                printf("l: %d, val:", l);
                printf("%d\n", nums.rbegin()+nums.size()-l);
                ret.insert(ret.end(), nums.rbegin()+nums.size()-1-l, nums.rend());
                break;
            }
        }
    }
    

    return ret;


}

int main() { 
    vector<int> t{-10000,-9999,-7,-5,0,0,10000};
    print_vector(t);
    print_vector(f(t));
    


}

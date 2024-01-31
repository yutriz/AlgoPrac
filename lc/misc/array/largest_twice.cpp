// You are given an integer array nums where the largest integer is unique.
// Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.


#include <vector>
#include <iostream>

using namespace std;

class SL {
public:
    int f(vector<int>& nums){
        int max = nums[0];
        int smax = 0;
        int index = 0;
        int i;
        for(i=1; i<nums.size(); i++){
           if (max < nums[i]) {
               smax = max;
               max = nums[i];
               index = i;
           } else if ( smax < nums[i]) {
               smax = nums[i];
           }
        }
        if (max >= smax*2) {
            return index;
        } else {
            return -1;
        }

    }
};

int main() {
    SL sl;
    vector<int> s = {1, 2, 3, 4, 5, 0};
    cout << sl.f(s) << endl;
    s = {8,9,3,2,0,0,0,2,3,99};
    cout << sl.f(s) << endl;
    s = {0,0,3,2};
    cout << sl.f(s) << endl;
}


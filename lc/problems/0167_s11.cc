#include "heads.h"
#include <vector>


/* no need */
int bs(vector<int>& nums, int nl, int nr, int target) {
    int l = nl;
    int r = nr;
    while (l<=r) {
        int mid = (l+r)/2;
        if(nums[mid]==target) {
            return mid;
        }
        if(target<nums[mid]) {
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    return -1;
}

vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size()-1;
    while(l<r) {
        if(numbers[l]+numbers[r]==target) 
            return vector<int> {l+1,r+1};
        if(numbers[l]+numbers[r]>target) {
                r--;
        } else {
                l++;
        }
    } 
    return vector<int> {0,0};
}        

void print(vector<int> v) {
    cout << "v1: " << v[0] <<", v2: "<< v[1]<<endl;
}

int main() {

    vector<int> n0={2,7,11,15};
    print(twoSum(n0,9));
    vector<int> n1={-1,-1};
    print(twoSum(n1, -2));
}

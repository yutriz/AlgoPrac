#include "heads.h"
#include <vector>

int binary_search(vector<vector<int>> nums, int n, int idx) {
    int r = nums.size()-1;
    int l = 0; /* both closed */
    while(l<=r) {
        int mid = (r+l)/2;
        if(n==nums[mid][idx])
            return mid;
        if(n>nums[mid][idx]) {
            l = mid+1;
        } else {
            r = mid-1;
        }
    }
    return l;
}

void print_intervals(vector<vector<int>> intervals) {
    for(auto i:intervals) {
        cout << i[0] << ", " << i[1] <<endl;
    }
}

/*
 * fx = { 1  (x in []s),
 *        0  others }
 *
 *
 *
 *
 */

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    int l,r;
    if(intervals.empty())
        return vector<vector<int>> {newInterval};

    if(newInterval[0]==0 && newInterval[1]==0) {
        intervals.insert(intervals.begin(), {0,0});
        return intervals;
    }
    l = binary_search(intervals, newInterval[0], 1);
    r = binary_search(intervals, newInterval[1], 0);
    vector<vector<int>> res;
    



    for(int i=0; i<l; i++)
        res.push_back(intervals[i]);
    
    vector<int> newintv(2,0);
      
    if(l==(int)intervals.size()) {
        newintv[0] = newInterval[0];
    } else {
    if(intervals[l][0] > newInterval[0]) {
        /* out */
        newintv[0] = newInterval[0];
    } else {
        /* int */ 
        newintv[0] = intervals[l][0];
    }
    }
   
    
    int is_zero = 0;
    if(r==(int)intervals.size() ||
       newInterval[1] < intervals[r][0] ) {
        if (r!=0) { 
            r--; 
        } else {
            is_zero = 1;
        }
    }

    if(intervals[r][1] < newInterval[1]) {
        newintv[1] = newInterval[1];
    } else {
        newintv[1] = intervals[r][1];
    }
    
    if(is_zero) {
        newintv = newInterval;
    }

    res.push_back(newintv);

    for(int i=r+1-is_zero; i<(int)intervals.size(); i++) 
        res.push_back(intervals[i]);

    return res;
}

int main() {
    vector<vector<int>> i1={{2,5},{6,7},{8,9}};
    vector<vector<int>> i2={{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<vector<int>> ie={};
    vector<int> ni1={0,1};
    vector<int> ni2={4,8};
    print_intervals(insert(i1,ni1));
    print_intervals(insert(i2,ni2));



}

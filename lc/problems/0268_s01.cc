#include <iostream>
#include <vector>

using namespace std;

int f(vector<int> &nums) {
    unsigned int sum = 0;
    for(auto n:nums) 
        sum += (unsigned int)n;
        
   return (nums.size()*(nums.size()+1)/2-sum); 
/*
 * 0 ~ n
 * n ~ 0 
 * n*(n+1)/2
 */

}

int main(){
    vector<int> n={0,1,2,3,4,5,6,7,9};
    cout << f(n) << endl;

}

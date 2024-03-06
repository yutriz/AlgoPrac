#include <iostream>
#include <vector>


/*
 * Moore's voting algorithm
 * */
using namespace std;
int f(vector<int> &nums){
    int party  = 0;
    int voters = 0;
    for(int i=0; i<nums.size(); i++){
        if (voters == 0) {
            party = nums[i];
            voters = 1;
            continue;
        }
            
        if(party == nums[i]){
            voters++;
        } else {
            voters--;
        }
        
    }
    return party;

}

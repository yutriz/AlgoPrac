#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> len;
    
    /* 
     * given a steel bar of N inches 
     * and prices of different lengths
     * cut it into many segments(keep it a whole one is ok which means no cutting)
     * 
     * calculate the maximum profile
     *
     * */

    for(int i=0; i<10; i++)
        len[i] = i;
    
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20, 24, 30};

    
    // max profile of n inches
    vector<int> max_prof = {1, 5, 8, 10, 13, 17, 18, 22, 25, 25, 30};

    



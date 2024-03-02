#include <vector>

#include <list>
#include <iostream>
#include <string>
using namespace std;

/* position + flag(high=1 bot=0) */
list<int[2]> find_peak(vector<int> arr) {
    list<int[2]> ret;
    /*flag: 1 ascending, 0 descending
     *      1 peak,      0 bottom
     */
    int flag = (arr[0]<arr[1]);
    ret.push_back({0, !flag});

    for(int i=1; i<arr.size(); i++) {
        if(flag == (arr[i]<arr[i+1])) {
            continue;
        } else {
            flag = !flag;
            ret.push_back({i, flag});
        }
    }            
        
    return ret;
}


int main() {
    vector<int> arr = {1,2,3,4,5,3,2,1,0,9,8,10,1};
    for(int i=0; i<arr.size(); i++) {
        cout << string(arr[i], '*') << endl;
    }
    auto l = find_peak(arr);
    for(auto i=l.begin(); i!=l.end(); i++) {
        printf("pos: %d, flag: %d\n", (*i)[0], (*i)[1]);
    }
}




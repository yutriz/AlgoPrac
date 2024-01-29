#include <iostream>
#include <vector>

using namespace std;

class SL {
    public:
        vector<int> f(vector<int>& nums) {
            for(vector<int>::iterator iter = nums.begin() + 1;
                iter != nums.end();
                iter++) {
                *iter = *iter + *(iter-1);
            }
            return nums;             
        }
};


int main() {
    vector<int> v = {1, 2, 3, 4};
    SL sl;
    vector<int> nv = sl.f(v);
    for(vector<int>::iterator iter = nv.begin();
        iter != nv.end();
        iter++) {
        cout << *iter << ", ";
    }
    cout << "end" << endl;

}






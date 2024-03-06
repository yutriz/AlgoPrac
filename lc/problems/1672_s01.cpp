#include <iostream>
#include <vector>

using namespace std;

class SL {
    public:
        int f(vector<vector<int>> &accounts) {
            int max = 0;
            for (unsigned long i=0; i<accounts.size(); i++) {
                int cm = 0;
                for(unsigned long j=0; j<accounts[i].size(); j++) {
                    cm += accounts[i][j];
                }
                if(max < cm)
                    max = cm;
            }
            return max;
        }
};


int main() {
    vector<vector<int>> acc = { {1,2,3},{3,2,1}};
    SL sl;
    cout << "is " << sl.f(acc) << endl;
}

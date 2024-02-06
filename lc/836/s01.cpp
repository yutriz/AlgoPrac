#include "../heads.h"

class SL {
public:
    bool f(vector<int>& rec1, vector<int>& rec2){
        return !(rec1[0]>=rec2[2] || rec1[1]>=rec2[3] ||
                 rec1[2]<=rec2[0] || rec1[3]<=rec2[1] );
    }
};

int main() {
    SL sl; 
    vector<int> a={7,8,13,15};
    vector<int> b={10,8,12,20};

    cout << sl.f(a, b);
}

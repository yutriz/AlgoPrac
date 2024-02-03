#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> v;
    v.push_back({1,1});

    for(auto i:v){
        cout  << "[" << i[0] << ", " << i[1] << "]" << endl;
    }
}



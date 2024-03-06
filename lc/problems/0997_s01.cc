#include "../heads.h"
#include <vector>


int f(int n, vector<vector<int>> &trust) {
    /* every pair is unique, so let vvi = {n, count} is ok */
    vector<vector<int>> vvi(n+1,{0}); 
    for(int i=0; (size_t)i<trust.size(); i++){
        int src=trust[i][0];
        int dst=trust[i][1];
        /* src  */
        if(vvi[src][0]==0){
            /* disable that src */
            vvi[src][0] = -1;
        }
        if(vvi[dst][0]==0){
            vvi[dst].push_back(src);
        }

    }
    for(int i=1; i<n+1; i++){
        if(vvi[i][0]==0 && vvi[i].size()==(size_t)n)
            return i;
    }

    return -1;

}

int main() {
    vector<vector<int>> t1= {{1,2}};
    cout <<f(2,t1) << endl;
}



#include "../heads.h"
#include "misc.hpp"
#include <vector>
#include <algorithm>


/* I ignored that 
 * token2score and score2token 
 * more exactly selling min token and buying max token
 * at the same time 
 * doesnt changes the score*/

int f(vector<int>& tokens, int power){
    if (tokens.empty())
        return 0;
    sort(tokens.begin(), tokens.end());
    if (power < tokens[0])
        return 0;

    int score = 0;
    auto l = tokens.begin();
    auto r = tokens.end()-1;

    while(l<=r){
        while (l!=tokens.end() && power>=*l) {
            power -= *l;
            l++;
            score++;
        }
        
        if(score>0 && r>l) {
            power += *r;
            r--;
            score--;
        } else {
            break;
        }

    }
   
    return score;
}

int main() {

    vector<int> vx={6,0,39,52,45,49,59,68,42,37};    
    sort(vx.begin(), vx.end());
    vector<int> v={0,0,0,0,0, 1333};
    vector<int> vv={4903,8812,6101,4671,6323,3378,1243,6825,6220,7885,1271,9117,7993,9168,8725};
//    cout << f(vv, 6810) << endl;
    sort(vv.begin(), vv.end());
    vector<int> c={5};
    cout << f(c, 10) << endl;
    cout << f(vv, 6810) << endl;
    //vector<int> vh={100,200,300,400};
    //cout << f(vh, 200) << endl;



}

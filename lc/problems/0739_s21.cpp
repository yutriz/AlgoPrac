#include "../heads.h"

/* NEED OPTI
 * time limit exceeded
 * given a very very ... very big vector 
 *
 * */

/*
 * ATTEMPT 1
 * reverse 
 *
 * ATTEMPT 2 
 * peak   failed
 *
 * ATTEMPT 3
 * stack 
 *
 * */


class SL {
public:
    vector<int> f(vector<int>& temperatures){
        if (temperatures.size() == 1) 
            return vector<int> {0};

        vector<int> result(temperatures.size(), 0);
        
        for(int i=0; i<(int)temperatures.size(); i++){
            if(temperatures[i] > min)
                min = temperatures[i];
                for(int j=0; j<i; j++){
                    result[j] = i - j;
                }
            }

        }

      
        return result;
    }



};

int main() {
    vector<int> s1={30,60,90};
    vector<int> s2={30,40,50,90};
    vector<int> s3={33,34,35,40,38,34,42,35,11};
    vector<int> s4={73,74,75,71,69,72,76,73};
    vector<int> s5={89,62,70,58,47,47,46,76,100,70};
    SL sl;

    /*
    for(auto a : sl.f(s1)) {
        cout << a << ' ';
    }
    cout << endl << endl;
    for(auto a : sl.f(s2)) {
        cout << a << ' ';
    }
    cout << endl << endl;
    for(auto a : sl.f(s3)) {
        cout << a << ' ';
    }
    cout << endl << endl;
    for(auto a : sl.f(s4)) {
        cout << a << ' ';
    }
    cout << endl << endl;
    */
    for(auto a : sl.f(s5)) {
        cout << a << ' ';
    }
    cout << endl << endl;

}

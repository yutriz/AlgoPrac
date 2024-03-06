#include "../heads.h"

/*
 * time limit exceeded
 * given a very very ... very big vector 
 *
 * */


class SL {
public:
    vector<int> f(vector<int>& temperatures){
    // a vector of same size 
    // result.end always 0
        if(temperatures.size() == 1)
            return vector<int> {0};
        
        vector<int> result(temperatures.size(), 0);

        vector<int> unsolved_temp;
        vector<int> unsolved_days;

        for(int i=0; i<(int)temperatures.size(); i++){
            if (unsolved_days.empty()) {
                if ((i+1)<(int)temperatures.size() && temperatures[i]<temperatures[i+1] ) {
                    result[i] = 1;
                    continue;
                }
                else {
                    goto pushi;
                }
                    
            }
            // stack not empty 

            // bigger than end of unsolved
            if (temperatures[i]>unsolved_temp[unsolved_temp.size()-1]) {
                while(temperatures[i]>unsolved_temp[unsolved_temp.size()-1] ) {
                        result[unsolved_days[unsolved_temp.size()-1]] = i - unsolved_days[unsolved_temp.size()-1];
                        unsolved_days.pop_back();
                        unsolved_temp.pop_back();
                        if (unsolved_days.empty())
                            break;
                }
                goto pushi;
            } 
            // smaller 
            else {
                goto pushi; 
            }

             
            pushi:{
                unsolved_temp.push_back(temperatures[i]);
                unsolved_days.push_back(i);
            }
            

        }
        return result;
    }



};

int main() {
    vector<int> s1={30,60,90};
    vector<int> s2={30,40,50,90};
    vector<int> s3={33,34,35,40,38,34,42,35,11};
    vector<int> s4={55,38,53,81,61,93,97,32,43,78};
    //vector<int> sx(20000, 99);
    SL sl;
    for(auto a : sl.f(s1)) {
        cout << a << ' ';
    }
    cout << endl;
    for(auto a : sl.f(s2)) {
        cout << a << ' ';
    }
    cout << endl;
    for(auto a : sl.f(s3)) {
        cout << a << ' ';
    }
    cout << endl;
    for(auto a : sl.f(s4)) {
        cout << a << ' ';
    }
    cout << endl;
    //sx[19999]=100;
    //for(auto a : sl.f(sx)) {
    //    cout << a << ' ';
    //}
    //cout << endl;

}

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
 * */


class SL {
public:
    vector<int> f(vector<int>& temperatures){
    // a vector of same size 
    // result.end always 0
        if (temperatures.size() == 1)
            return vector<int> {0};

        vector<int> peak_t, peak_day;
        if (temperatures[1] < temperatures[0]){
            peak_day.push_back(0);
            peak_t.push_back(temperatures[0]);
        }

        vector<int> result(temperatures.size(), 0);
        for(int i=1; i<temperatures.size()-1; i++){
            if( temperatures[i-1] < temperatures[i] && 
                temperatures[i+1] < temperatures[i] ) {
                peak_day.push_back(i);
                peak_t.push_back(temperatures[i]);
            }
        }
        if (temperatures[temperatures.size()-1] > temperatures[temperatures.size()-2]){
            peak_day.push_back(temperatures.size()-1);
            peak_t.push_back(temperatures[temperatures.size()-1]);
        }

        cout << "peak day" << endl;
        for (auto a:peak_day) {
            cout << a << ' ';
        }
        cout << endl;
        cout << "peak t" << endl;
        for (auto a:peak_t) {
            cout << a << ' ';
        }
        cout << endl;
        
        
        int peak_indicator = 0;
        for(int i=0; i<temperatures.size()-1; i++){
            if (i < peak_day[peak_indicator]) {
                if(temperatures[i] >= temperatures[i+1]){
                    for(int j=i; j<peak_day[peak_indicator]; j++) {
                        if (temperatures[i] < temperatures[j]){ 
                            result[i] = j - i;
                            break;
                        }
                    }
                } else {
                    result[i] = 1;
                }
            } else {
                // when i is peak 
                result[i] = 0;
                for(int peak_next_higher=peak_indicator+1; peak_next_higher<peak_day.size(); peak_next_higher++){
                    if(temperatures[i] < peak_t[peak_next_higher]){
                        // here error
                        result[i] = peak_day[peak_next_higher] - i;
                        cout << "test" << "\npeak_i is " << i << " and next higher peak is " << peak_next_higher << endl; 
                        break;
                    }
                } 
                peak_indicator++;
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

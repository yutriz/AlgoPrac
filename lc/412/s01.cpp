#include "../heads.h"


class SL {
    public:
        vector<string> f(int n) {
            vector<string> s(n);
            for(int i=0; i<n; i++) {
                s[i] = to_string(i+1);
            }
            for(int i=2; i<n; i+=3){
                s[i] = "Fizz";
            }
            for(int i=4; i<n; i+=5){
                s[i] = "Buzz";
            }
            for(int i=14; i<n; i+=15){
                s[i] = "FizzBuzz";
            }
            return s;
        }
};

int main() {
    SL sl;
    vector<string> result = sl.f(100);
    for(int i=0; i<100; i++){
        cout << i+1 << " is " << result[i] << endl;
    }
    

}

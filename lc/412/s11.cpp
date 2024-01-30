#include "../heads.h"

class SL {
    public:
        vector<string> f(int n) {
            vector<string> s(n);
            for(int i=1; i<n+1; i++) {
                if (i%3==0) {
                    if(i%5==0) {
                        s[i-1] = "FizzBuzz";
                    } else {
                        s[i-1] = "Fizz";                
                    }
                } else if (i%5==0) {
                    s[i-1] = "Buzz";
                } else {
                    s[i-1] = to_string(i);
                }
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

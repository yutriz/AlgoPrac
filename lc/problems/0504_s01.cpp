#include <string>
#include "../heads.h"

class SL {
public:
    string f(int num) {
        vector<char> reversed;
        string nega={};
        if(num<0){
            nega = {'-'};
            num=-num;
        } 

        do{
            reversed.push_back('0'+num%7);
            num /= 7;
        } while(num!=0);
            
        string str(reversed.rbegin(), reversed.rend());
        return nega.append(str);

    }
};

int main() {

    SL sl;
    cout << sl.f(100);

}

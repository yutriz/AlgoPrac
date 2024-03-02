#include "../heads.h"
#include <string>

string f(string s){
    int count_1 = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '1')
            count_1++;
    }
    
    return string(count_1-1,'1') + 
           string(s.size()-count_1, '0')+
           '1';
}

int main(){
    cout << f("10001000") << endl;
    

}


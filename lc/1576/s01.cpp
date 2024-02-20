#include "../heads.h"
#include <string>

class SL {
public:
    string f(string s){
        if(s[0]=='?') {
            if (s[1]!='z'){
                s[0] = 'z';
            } else {
                s[0] = 'y';
            }
        }

        if(s[s.length()-1]=='?') {
            if(s[s.length()-2]!='z'){
                s[s.length()-1]='z';
            } else {
                s[s.length()-1] = 'y';
            }
        }

        
        for(int i=1; i<s.length()-1; i++){
            if(s[i]=='?') {
                if(s[i-1]<'z') {
                    if (s[i+1]!=s[i-1]+1) {
                        s[i] = s[i-1]+1;
                    } else {
                        if (s[i-1] < 'y') {
                            s[i] = s[i-1]+2;
                        } else {
                            s[i] = 'a';
                        }
                    }
                } else {
                    /* s[i-1] == 'z' */
                    if (s[i+1]!='y') {
                        s[i] = s[i-1]-1;
                    } else {
                        s[i] = 'a';
                    }
                }
            }

        }
                

        return s;

    }


};

int main() {
    string sb="?abca???wo??asq???";
    SL sl;
    cout << sb << endl;
    cout << sl.f(sb) << endl;
}

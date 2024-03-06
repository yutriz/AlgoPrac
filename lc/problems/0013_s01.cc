#include "../heads.h"
#include <string>

int roman2int(string s){
    
    unsigned char cxi = 0;

    int ret = 0; 
    for(int i=s.size()-1; i>=0; i--) {
        if (s[i]=='I') {
            if (cxi>=1) {
                ret -= 1;
            } else {
                ret += 1;
            }
        } 
        if (s[i]=='V') {
            ret += 5;
            cxi = cxi | (1);
        }
        if (s[i]=='X') {
            if (cxi >= 1<<1) {
                ret -= 10;
            } else {
                ret += 10;
            }
            cxi = cxi | (1);
        }

        if (s[i]=='L') {
            ret += 50;
            cxi = cxi | 1<<1;
        }

        if (s[i]=='C') {
            if (cxi >= 1<<2) {
                ret -= 100;
            } else {
                ret += 100;
            }
            cxi = cxi | 1<<1;
        } 

        if (s[i]=='D') {
            ret += 500;
            cxi = cxi | 1<<2;
        }
        if (s[i]=='M') {
            ret += 1000;
            cxi = cxi | 1<<2;
        }
    }
    return ret;

}

int main() {
    cout << "III:\n"<< roman2int("III") << endl;
    cout << "MCMXCIV:\n"<< roman2int("MCMXCIV") << endl;
}

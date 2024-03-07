#include "heads.h"
#include <string>
#include <bits/stdc++.h>

string addBinary(string a, string b) {
    bool carry_up = 0;
    int pb = b.size()-1; 
    int pa = a.size()-1; 
    string ret;
    while(1) {
        int na = pa<0?'0':a[pa];
        int nb = pb<0?'0':b[pb];
        if (pa<0 && pb<0){
            break;
        } 
        if (na=='1' && nb=='1' && carry_up){
            carry_up = 1;
            ret += '1';
        } else if( (na=='1' && nb=='1') ||
            (na=='1' && carry_up)   ||
            (nb=='1' && carry_up)     ) {
                carry_up = 1;
                ret += '0';
        } else if ( na=='0' && nb=='0' && !carry_up) {
            carry_up = 0;
            ret += '0';
        } else {
            carry_up = 0;
            ret += '1';
        }
        pa--;
        pb--;
    }
    if(carry_up)
        ret+='1';
    ret = string(ret.rbegin(), ret.rend());
    
    return ret;
}

int main() {
    cout <<addBinary("1111", "1111") << endl;

}

#include "../heads.h"
#include <string>

/*
 * string s consists only 'a','b','c'
 * prefix
 * suffix 
 * prefix and suffix dont intersect
 *
 * */

int minumLength(string s) {

    int l = 0;
    int r = s.length();
    
    while(s[l]==s[r-1] && l<r) { 
        if (l+1==r)
            return 1;
        char c = s[l];
        while(s[l]==c && l<r) 
            l++;
        while(s[r-1]==c && l<r)
            r--;
    }
    return r-l;

}

int main() {
    string s0 = "cabaabac";
    string s1 = "c";
    string s2 = "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb";
    cout << minumLength(s0) << endl;
    cout << minumLength(s1) << endl;
    cout << minumLength(s2) << endl;


}

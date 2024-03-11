#include "heads.h"
#include <string>

string customSortString(string order, string s) {   
    string ret;
    int count[26]={0};
    for(int i=0; i<s.size(); i++){
        count[s[i]-'a']++;
    }
    for(int i=0; i<order.size(); i++){
        ret += string(count[order[i]-'a'], order[i]);
        count[order[i]-'a'] = 0;
    }
    for(int i=0; i<26; i++){
        ret += string(count[i], 'a'+i);
    }

    return ret;

}

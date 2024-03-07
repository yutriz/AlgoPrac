#include "heads.h"
#include <string>
#include <unordered_map>
#include <bitset>

bool wordPattern(string pattern, string s) {
    unordered_map<string, char> umap;
    int letters = 0;
    int ptr = 0;
    int i=0;
    for(; i<(int)pattern.size() && ptr<(int)s.size(); i++) {
        while(s[ptr]==' ')
            ptr++;
        int lptr = ptr;
        string word;
        while(ptr<(int)s.size() && s[ptr]!=' ') {
            ptr++;
        }
        word = s.substr(lptr, ptr-lptr);
        cout << word << " " << pattern[i]<<endl;
        cout << bitset<64>(letters) << endl;
        /* new word? */
        if(umap.find(word) == umap.end()) { 
            /* new letter */
            if ((letters>>(pattern[i]-'a')) & 1) {
                /* letter exists */
                return false;
            } else {
                /* letter dont */
                umap.insert({word, pattern[i]});
                letters |= 1<<(pattern[i]-'a');
            } 
        /* existed word */
        } else if(umap[word]!=pattern[i]) {
            return false;
        }
    }
    return (ptr==((int)s.size()) &&  i==(int)pattern.size());
}

int main() {
    string pattern  = "abba";
    string s= "do ca ac do";
    cout << wordPattern(pattern,s ) << endl;
}


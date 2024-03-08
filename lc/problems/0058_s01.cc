#include "heads.h"
#include <string>

int lengthOfLastWord(string s) {
    int i;
    for(i=s.size()-1; i>=0&&s[i]==' '; i--);
    int ii = i; 
    for(; i>=0&&s[i]!=' '; i--);

    return ii-i;

}

int main() {
    cout << lengthOfLastWord("hello world") << endl;
    cout << lengthOfLastWord("       ") << endl;
    


}

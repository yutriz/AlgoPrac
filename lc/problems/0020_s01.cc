#include "heads.h"
#include <stack>


bool isValid(string s) {
    stack<char> bstack;
    for(auto i:s) {
        if('{'==i || '['==i || '('==i) {
            bstack.push(i);
        } else if ( !bstack.empty() && 
                   (('}'==i && bstack.top()=='{') ||
                    (']'==i && bstack.top()=='[') ||
                    (')'==i && bstack.top()=='(')) ) {
                    bstack.pop();
        } else {
            return false;
        }

    }

    return bstack.empty();

}

int main(){
    stack<char> cs;
    cout << cs.top() <<endl;


}

#include "../heads.h"
#include <string>

int f(string moves) {
    int underline=0;
    int m=0;
    for(int i=0; i<moves.length(); i++){
        if(moves[i]=='_'){
            underline++;
            continue;
        }
        if(moves[i]=='L'){
            m++;
            continue;
        }
        if(moves[i]=='R'){
            m--;
        }
    }
    if (m>0)
        return m+underline;
    else
        return underline-m;
}

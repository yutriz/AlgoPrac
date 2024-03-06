#include "../heads.h"

#include <stdbool.h>

class SL {
public:
    bool f(int n) {
        if (n<=0)
            return 0;
        while(!(n&1)){
            n=n>>1;
        }
        n=n>>1;
        while(n){
            if(n&1){
                return 0;
            }
            n=n>>1;
        }
        return 1;

    
    };
    bool f2(int n){
      return (n>0 && !(n&(n-1)));
    }
};

int main() {
    110
     11

     11
     11


}

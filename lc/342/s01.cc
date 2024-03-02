#include "../heads.h"
#include <stdbool.h>

bool isPowOf4(int n) {
    
    if (n<=0)
        return 0;
    if (n==1)
        return 1;

    int bw=0;
    while(bw<31) {
        // 100000
        // 16 8 4 2 1
        if ( n == (1<<bw))
            return 1;
        bw+=2;
    }
    return 0;


}

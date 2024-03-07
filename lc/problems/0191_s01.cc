#include "heads.h"
#include <unitypes.h>

int hammingWeight(uint32_t n) {
    int w=0;
    for(int i=0; i<32; i++){
        w += (n>>i&1);
    }
    return w;
}

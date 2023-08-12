#include "stdio.h"

int main(){

    float big_p = 2e20 + 1;
    printf("2e20+1 is %f\n", big_p);
    float big_p_m = big_p - 2e20;
    printf("2e20+1-2e20 is %f\n\n", big_p_m);

    float norm = 2e5 + 1;
    printf("2e5+1 is %f\n", norm);
    float norm_m = norm - 2e5;
    printf("2e5+1-1 is %f\n", norm_m);

    return 0;
}

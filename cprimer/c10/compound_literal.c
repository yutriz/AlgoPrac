#include "stdio.h"

int main(){
    float *compound_arr = (float [5]){2, 3, 0.15, 5, 0.11};
    
    do_sth((float [5]){1,1,1,1,1}); // thus 

    // compared with
    float arrr[] = {1,2,3};
    do_sth(arrr);

    for(int i=0; i<5; i++)
        printf("cmpd_arr elemnt_%d: %f\n", i, compound_arr[i]);
}

void do_sth(float arr[]){
    ;
}
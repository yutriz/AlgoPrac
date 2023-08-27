#include "stdio.h"

int main(){
    int arr[20]={3,4};
    int arr_spe_index[20]={[10]=10};
    int arr_cm[]={1, 2, [10]=10, 1, 3};
    for(int i=0; i<20; i++){
        printf("%d\t%d\n", i, arr[i]);
    }
    printf("sizeof arr_cm is %d", sizeof(arr_cm)/sizeof(int));
}
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int n_sided_dice(int side){
    srand((unsigned int) time(0));
    puts("rolling the dice");
    return rand() % side + 1; 
}

int multi_dices(int n, int side){
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += n_sided_dice(n);
    }
    return sum;
}
#include "stdio.h"
#include "../../quickToolbox/dice.h"

extern int n_sided_dice(int);
extern int multi_dices(int n, int side);

int main(){
    printf("%d", n_sided_dice(6));
}
#include "stdio.h"

int main(void){
    const double hp2ap = 30;
    const double ap2hp = 1.6;
    double ap = 0, hp = 0;
    double p_ap, p_hp=150;

    for(int t=0; t<50; t++){
        p_ap = p_hp / hp2ap;
        p_hp = p_ap * ap2hp;
        ap += p_ap;
        hp += p_hp;
        printf("ap is %.8f, hp is %.8f\n", ap, hp);
    }

} 
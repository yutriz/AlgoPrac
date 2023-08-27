#include "stdio.h"

int main(void){
    int frd = 5;
    for(int week=1; frd<150; week++){
        frd = (frd-week) * 2;
        printf("week %3d -- friends %3d\n", week, frd);   
    }
}
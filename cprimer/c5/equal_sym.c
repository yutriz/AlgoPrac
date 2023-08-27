#include "stdio.h"

int main(void){
    int x,y;
    y=2+3*(x=7/3);
    printf("x=%d, y=%d\n", x, y);
    printf("\"x=3\"=%d", x=3);
    return 0;
}
#include "stdio.h"

int main(){
    float num;
    int width, p;
    printf("float num, width, precision:");
    scanf("%f,%d,%d", &num, &width, &p);
    printf("%*.*f", width, p, num);
    return 0;

}
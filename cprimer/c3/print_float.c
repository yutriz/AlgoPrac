#include "stdio.h"

int main(){
    float input;
    printf("enter a float number");
    scanf("%f", &input);
    printf("demical:%f\nScientific notation:%e\nHex:%a", input, input, input);
    return 0;

}
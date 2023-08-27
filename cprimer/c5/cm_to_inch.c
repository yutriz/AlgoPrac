#include "stdio.h"
#include "stdbool.h"
#define cm_to_inches 0.39370079

int main(void){
    float cms = 1;
    while(cms > 0){
        printf("enter your height in cm:");
        scanf("%f", &cms);
        float inches = cms * cm_to_inches;
        printf("%d feet %.2f inches\n", (int)inches/12, inches-(int)((int)inches/12*12));
    }
    return 0;
}
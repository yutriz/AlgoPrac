#include "stdio.h"

long factorial(int n){
    if (n > 0)
        return n*factorial(n-1); 
    else
        return 1;
}


int main(void){
    int c = 12;
    printf("12!=%d", factorial(c));


}
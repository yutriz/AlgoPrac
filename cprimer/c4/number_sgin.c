#include "stdio.h"

int main(){
    float f1 = 1;
    float f2 = 114.345;
    float f3 = 3.14e-33;

    char str[] = "f1 = 1\n"
                  "f2 = 114.345;\n"
                  "f3 = 3.14e-33;\n";
    printf("%s", str);
    printf("f1 %%#3.0f is %#3.0f\n",f1);
    printf("f1 %%3.0f is %3.0f",f1);


}
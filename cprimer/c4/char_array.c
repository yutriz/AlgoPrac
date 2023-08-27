#include "stdio.h"

int main(){
    char str[] = "a";
    char cha = 'a';
    printf("length of \"a\" is %d\n", sizeof(str));
    printf("length of \'a\' is %d\n", sizeof(cha));
    return 0;
}
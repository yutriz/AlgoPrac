#include <stdio.h>
struct LN {
    int val;
    struct LN *next;
};

struct LN* middle(struct LN* head) {
    LN* current = head;
    int ln_count = 1;
    while(current->next != NULL) {
        current = current->next; 
        ln_count++;
    }
    current = head;
    for(int i=0; i<ln_count/2; i++) {
        current = current->next;
    }
    return current;

}

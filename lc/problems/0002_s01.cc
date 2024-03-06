#include "../heads.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* ln = new ListNode;
    ListNode* ret = ln;
    int carry=0;
    while(1) {

        if (l1 != nullptr) {
            carry += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            carry += l2->val;
            l2 = l2->next;
        }

        if (carry>=10) {
            *ln=ListNode(carry-10);
            carry = 1;
        } else {
            *ln=ListNode(carry);
            carry = 0;
        } 
        
        if (l1==nullptr && l2==nullptr && carry==0)
            break;

        ln->next = new ListNode;
        ln = ln->next;
        

    }
    return ret;
    
}

int main(){
    return 0;
}

#include "../heads.h"
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) { 
   
    ListNode* ret = head;
    ListNode* cur = head;

    int len = 1;
    while(cur->next!=nullptr) {
        cur = cur->next;
        len++; 
    }

    /**/
    if (len==n)
        return head->next;

    cur = head;
    for(int i=1; i<len-n; i++) {
        cur = cur->next;
    }
    if(cur->next != nullptr)
        cur->next = cur->next->next;
    return ret;

}

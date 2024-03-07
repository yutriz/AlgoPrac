#include "heads.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* middleNode(ListNode* head) {
    ListNode* stride_one = head;
    ListNode* stride_two = head;
    /*
     * 1 2 3 4 5 6
     * 1 1
     * 2 3
     * 3 5
     * */

    while(
          stride_two != nullptr &&
          stride_two->next != nullptr ) {
        stride_one = stride_one->next;
        stride_two = stride_two->next->next;

    }
    return stride_one;




}

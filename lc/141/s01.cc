#include "../heads.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {

    ListNode* stride_one = head;
    ListNode* stride_two = head;
    while(stride_one!=NULL &&
          stride_two!=NULL &&
          stride_two->next!=NULL) {
        cout << "in loop" << endl;
        stride_one = stride_one->next;
        stride_two = stride_two->next->next;
        if (stride_one == stride_two)
            return 1;
    }
        
    return false;
}

int main(){
    ListNode a(5);
    cout << hasCycle(&a) << endl;


}

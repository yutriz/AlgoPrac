#include "heads.h"
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct p_and_index {
    ListNode* p;
    int index;
};

ListNode* removeZeroSumSublists(ListNode* head) {
    if(head == nullptr)
        return head;

    unordered_map<int, p_and_index> umap;    
    ListNode* p = head;
    ListNode* p_ret = head;
    int sum = 0;
    int max_cut = 0;
    ListNode *l,*r;
    l = head;
    r = head->next;
    umap.insert({0, p_and_index{nullptr, -1}}); 
    int index = 0; 
    while(p!=nullptr) {
        sum += p->val; 
        if(umap.find(sum) == umap.end()) {
            umap.insert({sum, p_and_index{p, index}});
        } else {
            p_and_index pai = umap[sum];
            if (int len=index-pai.index; len>max_cut) {
                l = pai.p;
                r = p->next;
                max_cut = len;
            }
        }
        p = p->next;
        index++;
    }

    if (l==nullptr) {
        p_ret = r;
    } else {
        l->next = r;
    }
    return p_ret;
}

int main() {
    ListNode* ln = new ListNode[5];
    ln[0]=1;
    ln[1]=1;
    ln[2]=1;
    ln[3]=2;
    ln[4]=-2;
    for(int i=0; i<4; i++){
        ln[i].next = &ln[i+1];       
    }
    ln[3].next = nullptr;
    ln[4].next = nullptr;
    
    
    ListNode c{1,nullptr};
    ListNode* r = removeZeroSumSublists(ln);
    while(r!=nullptr) {
        cout << r->val << ", ";
        r = r->next;
    }
    cout << "\n";



}

#include "heads.h"
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* removeZeroSumSublists(ListNode* head) {

    unordered_map<int, ListNode*> umap;    
    ListNode* p = head;
    ListNode* p_ret = head;
    int sum = 0;

    umap.insert({0, head}); 

    while(p!=nullptr) {
        sum += p->val; 
        if(auto iter_p=umap.find(sum); iter_p == umap.end()) {
            umap.insert({sum, p}); 
        } else {
            /* found */
            if (sum==0) {
                p_ret = p->next;
                umap.clear();
                umap.insert({0, head}); 
                
            } else {
                ListNode* pp = iter_p->second;
                ListNode* ppp = pp->next;
                int tsum = sum;
                while(ppp!=p) {
                    tsum += ppp->val;
                    umap.erase(tsum);
                    ppp = ppp->next;
                } 
                pp->next = p->next;
            }
        }
        p = p->next;
    }
    /* 0| 1 4 6 3 1 6 11 6 7 */
    /* 0| 2 4 2 3 2 1*/
    /* 0| 1 1 1 0 2 1 1*/
    return p_ret;
}

int main() {
    ListNode* ln = new ListNode[9];
    ln[0]=1;
    ln[1]=0;
    ln[2]=0;
    ln[3]=-1;
    ln[4]=2;
    ln[5]=-1;
    ln[6]=0;
    ln[7]=0;
    ln[8]=0;
    for(int i=0; i<8; i++){
        ln[i].next = &ln[i+1];       
    }
    ln[6].next = nullptr;
    
    ListNode c{1,nullptr};
    ListNode* r = removeZeroSumSublists(ln);
    for(int i=0; i<7; i++)
        cout << &ln[i] << endl;
    while(r!=nullptr) {
        cout << r->val << ", ";
        r = r->next;
    }
    cout << "\n";



}

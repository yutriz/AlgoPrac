#include "../heads.h"
#include <stdbool.h>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==q)
        return 1;
    if(p==nullptr && q==nullptr)
        return 1;
    if(p==nullptr || q==nullptr)
        return 0;

    if(p->val != q->val)
        return 0;

    if(isSameTree(p->left, q->left) &&
       isSameTree(p->right, q->right))
        return 1;

    return 0;

}

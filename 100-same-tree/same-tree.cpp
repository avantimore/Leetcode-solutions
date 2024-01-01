/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)return 1;
        if(!p && q)return 0;
        if(p && !q)return 0;
        if(p->val!=q->val)return 0;

        bool lt = isSameTree(p->left,q->left);
        bool rt = isSameTree(p->right,q->right);
        return (lt && rt);
    }
};
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
    bool solve(TreeNode* p, TreeNode* q){
        if(!p && !q)return 1;
        if(!p || !q || (p->val!=q->val)) return 0;

        return solve(p->right,q->left) && solve(p->left,q->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return 1;
        return solve(root->left,root->right);
    }
};
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
    bool validBstHelp(TreeNode* root, long long maxi, long long mini){
        if(root==NULL)return true;
        if(root->val>=maxi || root->val<=mini){
            return false;
        }
        bool left = validBstHelp(root->left,root->val, mini);
        bool right = validBstHelp(root->right,maxi,root->val);

        return (left && right);
    }
    bool isValidBST(TreeNode* root) {
        long long maxi = 2147483649;
        long long mini = -2147483649;

        return validBstHelp(root,maxi,mini);

    }
};
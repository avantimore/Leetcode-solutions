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
    bool isBST(TreeNode* root,long long mini,long long maxi){
        if(!root)return 1;
        if(root->val>=maxi || root->val<=mini ){
            return 0;
        }
        return isBST(root->left,mini,root->val) && isBST(root->right,root->val,maxi);

    }
    bool isValidBST(TreeNode* root) {
        if(!root){
            return 1;
        }
        
        bool lt = isBST(root->left,-9223372036854775808,root->val);
        bool rt = isBST(root->right,root->val,9223372036854775807);

        return (lt && rt);
    }
};
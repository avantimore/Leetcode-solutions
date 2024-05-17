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
    int postorder(TreeNode* root){
        if(root->right==NULL && root->left==NULL){
            return root->val;
        }
        int left = postorder(root->left);
        int right = postorder(root->right);
        int ans = 1;
        if(root->val==2){
            ans = left || right;
        }
        else{
            ans = left && right;
        }
        return ans;
    }
    bool evaluateTree(TreeNode* root) {
        int ans = postorder(root);
        return ans;
    }
};
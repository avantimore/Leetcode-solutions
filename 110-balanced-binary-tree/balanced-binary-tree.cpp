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
    pair<int,bool> solve(TreeNode* root){
        if(!root) return {0,1};
        pair<int,bool> left = solve(root->left);
        pair<int,bool> right =  solve(root->right);
        bool ans = (abs(left.first-right.first)<=1)?1:0; 
        if(ans) ans = right.second && left.second;
        return {max(right.first,left.first)+1,ans};
    }
    bool isBalanced(TreeNode* root) {
        return solve(root).second;
    }
};
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
    int maxDiam(TreeNode* root,int &maxi){
        if(!root) return 0;
        int rh = maxDiam(root->right,maxi);
        int lh = maxDiam(root->left,maxi);
        maxi = max(maxi,rh+lh);
        return max(rh,lh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diam = 0;
        maxDiam(root,diam);
        return diam;
    }
};
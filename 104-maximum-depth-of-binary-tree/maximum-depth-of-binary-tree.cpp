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
    void inorder(TreeNode* root, int level,int &maxHt){
        if(root==NULL)return ;
        maxHt = max(maxHt,level);
        inorder(root->left,level+1,maxHt);
        inorder(root->right,level+1,maxHt);
    }
    int maxDepth(TreeNode* root) {
        int maxHt = INT_MIN;
        if(root==NULL)return 0;
        int level = 1;
        inorder(root,level,maxHt);

        return maxHt;
    }
};
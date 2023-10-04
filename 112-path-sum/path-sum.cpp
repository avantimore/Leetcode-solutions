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
    void inorder(TreeNode* root, int k,int sum,bool &flag){
        if(root==NULL){
            return ;
        }
        if(!root->left && !root->right){
            sum+=root->val;
            if(sum==k){
                flag =1;
            }
        }
        sum += root->val;
        inorder(root->left,k,sum,flag);
        inorder(root->right,k,sum,flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool flag=0;
        inorder(root,targetSum,sum,flag);
        return flag;
    }
};
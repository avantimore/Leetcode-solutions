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
    void inorder(TreeNode* root, int k,int sum,vector<vector<int>> &ans,vector<int> &temp){
        if(root==NULL){
            return;
        }
        if(!root->right && !root->left && root->val+sum==k){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
        }
        temp.push_back(root->val);
        inorder(root->left,k,sum+root->val,ans,temp);
        inorder(root->right,k,sum+root->val,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int sum=0;
        vector<int> temp;
        inorder(root,targetSum,sum,ans,temp);
        return ans;
    }
};
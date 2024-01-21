/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void lowestCommonAncestorHelper(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &ans){
        if(!root){
            return ;
        }
        if(root->val==p->val){
            ans=p;
            return ;
        }
        if(root->val==q->val){
            ans=q;
            return ;
        }
        if((root->val>q->val && root->val<p->val)){
            ans=root;
            return;
        }
        if((root->val<q->val && root->val>p->val)){
            ans=root;
            return;
        }
        if(root->val>q->val && root->val>p->val){
            lowestCommonAncestorHelper(root->left,p,q,ans);
        }
        else{
            lowestCommonAncestorHelper(root->right,p,q,ans);
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr = root;
        lowestCommonAncestorHelper(root,p,q,curr);
        return curr;
    }
};
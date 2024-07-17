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
    int find(vector<int>& inorder,int num,int n){
        for(int i=0;i<n;i++){
            if(inorder[i]==num)return i;
        }
        return 0;
    }

    TreeNode* build(int &i,int s,int e,vector<int>& preorder, vector<int>& inorder,int n){
        if(s>e)return NULL;
        int num = preorder[i++];
        TreeNode* root = new TreeNode(num);
        int ind = find(inorder,num,n);

        root->left = build(i,s,ind-1,preorder,inorder,n);
        root->right = build(i,ind+1,e,preorder,inorder,n);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i=0;
        int e = inorder.size()-1;
        int s = 0;
        int num = preorder[i++];
        TreeNode* root = new TreeNode(num);
        int ind = find(inorder,num,e+1);

        root->left = build(i,s,ind-1,preorder,inorder,e+1);
        root->right = build(i,ind+1,e,preorder,inorder,e+1);

        return root;
    }
};
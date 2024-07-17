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
        int num = preorder[i--];
        TreeNode* root = new TreeNode(num);
        int ind = find(inorder,num,n);

        root->right = build(i,ind+1,e,preorder,inorder,n);
        root->left = build(i,s,ind-1,preorder,inorder,n);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int e = inorder.size()-1;
        int i=inorder.size()-1;
        int s = 0;
 
        return build(i,s,e,postorder,inorder,e+1);
    }
};
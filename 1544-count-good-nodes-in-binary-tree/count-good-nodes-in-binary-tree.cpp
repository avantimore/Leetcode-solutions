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
    // void postOrder(TreeNode* root,int &count,int &curr){
    //     if(root==NULL)return;
    //     if(!root->left && !root->right){
    //         curr = root->val;
    //         count++;
    //         return;
    //     }
        
    //     postOrder(root->left,count,curr);
    //     postOrder(root->right,count,curr);

    //     if(root->val<curr){
    //         count++;
    //         curr = max(curr,root->val);
    //     }
    // }
    // int goodNodes(TreeNode* root) {
    //     int count = 0;
    //     int curr=0;
    //     postOrder(root,count,curr);
    //     return count;
    // }

    void postOrder(TreeNode* root, int &count, int curr) {
    if (root == NULL) return;

    // Update curr to be the maximum of current node's value and curr
    curr = max(curr, root->val);

    if (root->val >= curr) {
        // If the current node's value is greater or equal to curr, it's a good node
        count++;
    }

    postOrder(root->left, count, curr);
    postOrder(root->right, count, curr);
}

int goodNodes(TreeNode* root) {
    int count = 0;
    int curr = root->val; // Initialize curr with the root's value
    postOrder(root, count, curr);
    return count;
}

};
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
    bool inorder(TreeNode* root, int k, int sum) {
    if (root == NULL) {
        return false;
    }

    // Check if the current node is a leaf node and if the sum matches the target
    if (!root->left && !root->right && sum + root->val == k) {
        return true;
    }

    // Update the sum and continue searching in the left and right subtrees
    sum += root->val;
    return inorder(root->left, k, sum) || inorder(root->right, k, sum);
}

bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0;
    return inorder(root, targetSum, sum);
}

};
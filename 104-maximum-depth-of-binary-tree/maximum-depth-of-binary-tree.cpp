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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
        return 0;
    }

        int depth = 0;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at the current level

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* current = q.front();
                q.pop();

                // Process the current node

                if (current->left) {
                    q.push(current->left);  // Enqueue left child
                }

                if (current->right) {
                    q.push(current->right);  // Enqueue right child
                }
            }

            ++depth;  // Completed processing nodes at the current level
        }
        return depth;
    }
};
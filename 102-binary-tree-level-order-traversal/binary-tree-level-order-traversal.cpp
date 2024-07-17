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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        vector<int> temp;

        queue<TreeNode*> q;
        q.push(root);
        // temp.push_back(root->val);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* qfront = q.front();
            q.pop();

            if (qfront == nullptr) {
                ans.push_back(temp);
                temp.clear();
                if (!q.empty()) {
                    q.push(nullptr); // Add marker for next level end
                }
            } else {
                temp.push_back(qfront->val);
                if (qfront->left) {
                    q.push(qfront->left);
                }
                if (qfront->right) {
                    q.push(qfront->right);
                }
            }
        }
        return ans;
    }
};
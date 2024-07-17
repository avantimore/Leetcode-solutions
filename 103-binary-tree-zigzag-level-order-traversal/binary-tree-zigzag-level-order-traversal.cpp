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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        bool order = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            int s =0;
            int e = size;
            
            for(int i=0;i<size;i++){
                TreeNode* qfront = q.front();
                q.pop();
                v.push_back(qfront->val);
                if(qfront->left) q.push(qfront->left);
                if(qfront->right) q.push(qfront->right);
            }
            if(order) reverse(v.begin(),v.end());
            ans.push_back(v);
            order = !order;
        }
        return ans;
    }
};
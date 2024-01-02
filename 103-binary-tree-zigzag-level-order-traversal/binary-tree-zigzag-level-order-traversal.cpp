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
        vector<vector<int>> ans;
        if(root==NULL){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);

        bool order = 1;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp(size);
            if(order){
                for(int i=0;i<size;i++){
                    TreeNode* qfront = q.front();
                    q.pop();
                    if(qfront->left){
                        q.push(qfront->left);
                    }
                    if(qfront->right){
                        q.push(qfront->right);
                    }
                    temp[i] = qfront->val;
                }
            }
            else{
                for(int i=size-1;i>=0;i--){
                    TreeNode* qfront = q.front();
                    q.pop();
                    if(qfront->left){
                        q.push(qfront->left);
                    }
                    if(qfront->right){
                        q.push(qfront->right);
                    }
                    temp[i] = qfront->val;
                }
            }
            ans.push_back(temp);
            order = !order;

        }
        return ans;
    }
};
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
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        q.push(root);
        bool odd = true;
        while(!q.empty()){
            int n = q.size();
            vector<int> res;
            while(n--){
                TreeNode* ele = q.front();
                q.pop();
                if(ele->left) q.push(ele->left);
                if(ele->right) q.push(ele->right);
                res.push_back(ele->val);
            }
            if(!odd){
                reverse(res.begin(), res.end());
            }
            ans.push_back(res);
            odd = !odd;
        }
        return ans;
    }
};
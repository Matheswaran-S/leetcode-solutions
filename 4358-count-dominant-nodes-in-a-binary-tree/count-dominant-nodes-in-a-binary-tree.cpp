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
private:
    int ans = 0;
public:
    int dfs(TreeNode* root){
        if(!root) return INT_MIN;
        if(!root->left && !root->right){
            ans++;
            return root->val;
        }

        int left = dfs(root->left);
        int right = dfs(root->right);
        int mx = max(left,right);
        ans += (root->val >= mx);
        return max(root->val, mx);
    }
    int countDominantNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
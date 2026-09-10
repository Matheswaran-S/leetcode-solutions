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
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if(!(root->left) && !(root->right)){
            ans = max(ans, root->val);
            return max(0,root->val);
        }
        int l = root->val , r = root->val;
        if(root->left) l += dfs(root->left);
        if(root->right) r += dfs(root->right);
        ans = max(ans, l+r-root->val);
        return max({0,l,r});
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
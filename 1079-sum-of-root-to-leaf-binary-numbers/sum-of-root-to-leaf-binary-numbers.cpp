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
    int dfs(TreeNode* root, int v){
        v = (v<<1)|root->val;
        if(!root->left && !root->right) return v;
        int l = 0;
        if(root->left) l = dfs(root->left, v);
        int r = 0;
        if(root->right) r = dfs(root->right, v);
        return l+r;
    }
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);   
    }
};
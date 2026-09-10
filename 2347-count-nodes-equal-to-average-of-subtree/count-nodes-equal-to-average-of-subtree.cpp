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
    int cnt = 0;
    pair<int,int> dfs(TreeNode* root){
        if(!(root->left) && !(root->right)){
            cnt++;
            return {root->val, 1};
        }
        pair<int,int> l={0,0}, r={0,0};
        if(root->left) l = dfs(root->left);
        if(root->right) r = dfs(root->right);
        int sum = root->val + l.first + r.first, tot = 1+l.second+r.second;
        if(sum/tot == root->val) cnt++;
        return {sum,tot};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return cnt;
    }
};
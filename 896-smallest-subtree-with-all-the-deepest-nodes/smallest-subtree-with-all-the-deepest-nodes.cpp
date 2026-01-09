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
    pair<int,TreeNode*> dfs(int d, TreeNode* root){
        if(root == NULL){
            return {0,NULL};
        }
        auto l = dfs(d, root->left);
        auto r = dfs(d, root->right);
        if(l.first == r.first) return {l.first+1, root};
        else if(l.first > r.first) return {l.first+1, l.second};
        else return{r.first+1, r.second};
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return(dfs(0,root).second);
    }
};
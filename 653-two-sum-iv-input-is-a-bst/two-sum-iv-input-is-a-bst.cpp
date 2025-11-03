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
    void tsum(TreeNode* root, int k, auto &mpp, bool &ok){
        if(root == NULL) return;
        tsum(root->left, k, mpp, ok);
        if(mpp[k - root->val]){
            ok = true;
            return;
        }
        mpp[root->val] = 1;
        tsum(root->right, k, mpp, ok); 
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int> mpp;
        bool ok = false;
        tsum(root, k, mpp, ok);
        return ok;
    }
};
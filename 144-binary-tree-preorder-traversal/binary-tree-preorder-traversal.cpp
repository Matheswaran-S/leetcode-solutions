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
    struct TreeNode* pT(TreeNode* temp,vector<int> &v){
        if(temp == NULL) return NULL;
        else{
            if(temp->val != -101) {
                v.push_back(temp->val);
                temp->val = -101;
            }
            pT(temp->left,v);
            pT(temp->right,v);
        }
        return NULL;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        struct TreeNode* temp = root;
        pT(temp,v);
        return v;
    }
};
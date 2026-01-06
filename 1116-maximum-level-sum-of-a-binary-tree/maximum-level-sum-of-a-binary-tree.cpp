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
    int maxLevelSum(TreeNode* root) {
        queue<vector<TreeNode*>> q;
        q.push({root});
        int ma = root->val, small = 1, lev = 1;
        while(!q.empty()){
            auto front = q.front();
            q.pop();
            int cnt = 0;
            bool found = false;
            vector<TreeNode*> temp;
            lev++;
            for(auto el : front){
                if(el->left){
                    found = true;
                    cnt += el->left->val;
                    temp.push_back(el->left);
                }
                if(el->right){
                    found = true;
                    cnt += el->right->val;
                    temp.push_back(el->right);
                }
            }
            if(found){
                if(cnt > ma){
                    ma = cnt;
                    small = lev;
                }
            }
            if(!temp.empty()) q.push(temp);
        }
        return small;
    }
};
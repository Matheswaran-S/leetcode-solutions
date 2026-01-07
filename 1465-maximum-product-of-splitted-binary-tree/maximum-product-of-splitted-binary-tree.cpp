#define mod 1000000007
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
    long long pre(TreeNode* root, long long sum, long long tot, long long &maxi, bool ans){
        if(root == NULL) return 0;
        sum = root->val+pre(root->left, sum, tot, maxi, ans)+pre(root->right, sum, tot, maxi, ans);
        if(ans) maxi = max(maxi, sum*(tot-sum));
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long maxi = LLONG_MIN, sum = pre(root, 0, 0, maxi, false);
        pre(root, 0, sum, maxi, true);
        return maxi%mod;
    }
};
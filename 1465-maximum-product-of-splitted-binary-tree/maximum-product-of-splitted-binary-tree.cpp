#define mod 1000000007
#define ll long long
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
    int pre(TreeNode* root, int tot, long long &maxi, bool ans){
        if(root == NULL) return 0;
        int sum = root->val+pre(root->left, tot, maxi, ans)+pre(root->right, tot, maxi, ans);
        if(ans) maxi = max(maxi, (ll)sum*(ll)(tot-sum));
        return sum;
    }
public:
    int maxProduct(TreeNode* root) {
        long long maxi = LLONG_MIN;
        int sum = pre(root, 0, maxi, false);
        pre(root, sum, maxi, true);
        return maxi%mod;
    }
};
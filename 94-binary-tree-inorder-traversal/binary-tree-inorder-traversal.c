/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root, int* arr, int* i){
    if(root != NULL){
        inorder(root->left, arr, i);
        arr[*i] = root->val;
        (*i)++;
        inorder(root->right, arr, i);
    }
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* arr = (int*)malloc(100*sizeof(int));
    int i = 0;
    inorder(root, arr, &i);
    *returnSize = i;
    return arr;
}
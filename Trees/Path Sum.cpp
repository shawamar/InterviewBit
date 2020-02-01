/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Solution::hasPathSum(TreeNode* A, int B) {
    TreeNode* root=A;
    if(root == NULL)
    {
        return 0;
    }
    
    if(root->val == B && root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    
    return max(hasPathSum(root->left, B - root->val), hasPathSum(root->right, B - root->val));
}

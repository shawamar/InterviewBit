/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int isSymmetricHelper(TreeNode* root1, TreeNode* root2)
{
    if (!root1 || !root2)
        return root1 == root2;
    if (root1->val != root2->val)
        return 0;
        
    return isSymmetricHelper(root1->left, root2->right) && 
            isSymmetricHelper(root1->right, root2->left);
}
int Solution::isSymmetric(TreeNode* A) {
    return A == NULL || isSymmetricHelper(A->left, A->right);
}
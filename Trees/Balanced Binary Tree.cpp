/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int Solution::isBalanced(TreeNode* A) {
    TreeNode* root=A;
    if(root == NULL)
    {
        return 1;
    }
    else if(root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else if(root->left != NULL && root->right != NULL)
    {
        return min(isBalanced(root->right), isBalanced(root->left));
    }
    else if(root->left == NULL)
    {
        if(root->right != NULL)
        {
            TreeNode* temp = root->right;
            if(temp->right != NULL || temp->left != NULL)
            {
                return 0;
            }
        }
        return 1;
    }
    else if(root->right == NULL)
    {
        if(root->left != NULL)
        {
            TreeNode* temp = root->left;
            if(temp->right != NULL || temp->left != NULL)
            {
                return 0;
            }
        }
        return 1;
    }
    return 1;
}

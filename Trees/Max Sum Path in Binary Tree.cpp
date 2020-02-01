/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int findMaxUtil(TreeNode* root, int &res) 
{ 
    if (root == NULL) 
        return 0; 
    
    int l = findMaxUtil(root->left,res); 
    int r = findMaxUtil(root->right,res); 
  
    int max_single = max(max(l, r) + root->val, root->val); 
    int max_top = max(max_single, l + r + root->val); 
  
    res = max(res, max_top); // Store the Maximum Result. 
  
    return max_single; 
} 
int Solution::maxPathSum(TreeNode* A) {
    int res = INT_MIN; 
    findMaxUtil(A, res); 
    return res;
}

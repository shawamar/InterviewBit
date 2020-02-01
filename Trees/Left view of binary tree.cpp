/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void leftViewUtil(TreeNode* root, int level, int* max_level,vector<int> &ans) 
{ 
    if (root == NULL) 
        return; 
  
    if (*max_level < level) { 
        ans.emplace_back(root->val); 
        *max_level = level; 
    } 
  
    leftViewUtil(root->left, level + 1, max_level,ans); 
    leftViewUtil(root->right, level + 1, max_level,ans); 
} 
vector<int> Solution::solve(TreeNode* A) {
    int max_level = 0; 
    vector<int> sol;
    leftViewUtil(A, 1, &max_level,sol);
    return sol;
}

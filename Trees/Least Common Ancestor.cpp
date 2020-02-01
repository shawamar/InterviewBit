/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool findPath(TreeNode *root, vector<int> &path, int k) 
{ 
    if (root == NULL) return false; 
  
    path.push_back(root->val); 
  
    if (root->val == k) 
        return true; 
  
    if ( (root->left && findPath(root->left, path, k)) || 
         (root->right && findPath(root->right, path, k)) ) 
        return true; 
  
    path.pop_back(); 
    return false; 
} 
 
int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> path1, path2; 
  
    if ( !findPath(A, path1, B) || !findPath(A, path2, C)) 
          return -1; 
  
    int i; 
    for (i = 0; i < path1.size() && i < path2.size() ; i++)
    {
        if (path1[i] != path2[i]) 
            break; 
    }
    return path1[i-1];
}


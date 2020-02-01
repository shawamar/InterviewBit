/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void putSum(TreeNode* root, vector<vector<int> >& sol, int sum, vector<int>& v){
    if(sum == 0 && root->left == NULL && root->right == NULL){
        sol.push_back(v);
    }
    
    if(root->left != NULL){
        v.push_back((root->left)->val);
        putSum(root->left, sol, sum - (root->left)->val, v);
        v.pop_back();
    }
    
    if(root->right != NULL){
        v.push_back((root->right)->val);
        putSum(root->right, sol, sum - (root->right)->val, v);
        v.pop_back();
    }
    
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<vector<int> > sol;
    vector<int> v;
    TreeNode* root=A;
    if(root == NULL){
        return sol;
    }
    
    v.push_back(root->val);
    
    putSum(root, sol, B - root->val, v);
    
    return sol;
 
}
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void zig(TreeNode* A, vector<vector<int> >& sol, bool left, int level)
{
    if(A == NULL){
        return;
    }
    
    if(sol.size() < level){
        vector<int> temp;
        sol.push_back(temp);
    }
    
    if(left){
        sol[level-1].push_back(A->val);
    }
    else{
        sol[level-1].insert(sol[level-1].begin(), A->val);
    }
    
    zig(A->left, sol, !left, level+1);
    zig(A->right, sol, !left, level+1);
}
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    vector<vector<int> > sol;
    zig(A, sol, true, 1);
    return sol;
}

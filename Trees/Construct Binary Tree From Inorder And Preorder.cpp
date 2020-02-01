/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
int index(vector<int> &inorder, int val, int start, int end){
    int i;
    for(i = start; i <= end; i++)
    {
        if(inorder[i] == val)
        {
            return i;
        }
    }
    return -1;
} 
 
TreeNode* make(vector<int> &preorder, vector<int> &inorder, int start, int end, int &preInd){
    if(start > end)
    {
        return NULL;
    }
    
    TreeNode* root = new TreeNode(preorder[preInd]);
    preInd++;
    
    if(start == end)
    {
        return root;
    }
    
    int ind = index(inorder, root->val, start, end);
    
    root->left = make(preorder, inorder, start, ind-1, preInd);
    root->right = make(preorder, inorder, ind+1, end, preInd);
    
    return root;
} 
TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int pre = 0;
    return make(A, B, 0, A.size()-1, pre);
}
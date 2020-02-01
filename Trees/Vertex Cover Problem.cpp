/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void traverse(TreeNode *A)
 {
    if(A==NULL)
        return ;
    A->val=0;
    traverse(A->left);
    traverse(A->right);
 }
 int vCover(TreeNode* A)
 {
     if(A==NULL)
        return 0;
    if(A->right==NULL && A->left==NULL)
        return 0;
    if(A->val!=0)
        return A->val;
    int s1=1+ vCover (A->left)+ vCover (A->right);
    int s2=0;
    if(A->left!=NULL)
        s2+=1+vCover(A->left->left)+vCover(A->left->right);
    if(A->right!=NULL)
        s2+=1+vCover(A->right->left)+vCover(A->right->right);
    return A->val=min(s2,s1);    
 }
int Solution::solve(TreeNode* A) {
    int count=0;
    traverse(A);
    return vCover(A);
}
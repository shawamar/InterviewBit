/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::preorderTraversal(TreeNode* A) {
    vector<int> sol;
    TreeNode* curr = A;
    stack<TreeNode*> st;
    
    if(A == NULL)
    {
        return sol;
    }
    
    do
    {
        if(curr == NULL)
        {
            curr = st.top();
            st.pop();
            curr = curr->right;
            if(curr != NULL)
            {
                sol.push_back(curr->val);
                st.push(curr);
                curr = curr->left;    
            }
            
        }
        else
        {
            sol.push_back(curr->val);
            st.push(curr);
            curr = curr->left;
        }
    }while(!st.empty());
    
    return sol;
 
}
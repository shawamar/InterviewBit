/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    vector<int> ans;
    stack<TreeNode*> st;
    
    TreeNode* curr = A;
    bool done = false;
    
    while(!done)
    {
        if(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if(!st.empty())
            {
                curr = st.top();
                int val = curr->val;
                ans.push_back(val);
                curr = curr->right;
                st.pop();
            }
            else
            {
                done = true;
            }
        }
    }
    
    return ans;
}
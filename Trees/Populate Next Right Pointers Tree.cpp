/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {
    if(A == NULL)
        return;
    queue<pair<int, TreeLinkNode*> > q;
    q.push({0, A});
 
    while(!q.empty())
    {
        pair<int, TreeLinkNode*> temp = q.front();
 
        int level = temp.first;
        q.pop();
 
//      Keep putting the nodes until we are on the same level.
        while(!q.empty() and q.front().first == level)
        {
            if(temp.second->left)
                q.push({level+1, temp.second->left});
            if(temp.second->right)
                q.push({level+1, temp.second->right});
 
            temp.second->next = q.front().second;
            temp = q.front();
 
            q.pop();
        }
//      
        temp.second->next = NULL;
        
//      if the control doesn't enter the above while loop, accomodate
//      the left out nodes. (Consider a three node tree!)
        if(temp.second->left)
            q.push({level+1, temp.second->left});
        if(temp.second->right)
            q.push({level+1, temp.second->right});
    }
}
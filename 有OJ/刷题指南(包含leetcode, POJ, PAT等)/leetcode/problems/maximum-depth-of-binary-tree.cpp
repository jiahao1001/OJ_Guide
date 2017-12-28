/*********************************************************
* problem id : 104
* problem title : Maximum Depth of Binary Tree
* problem link : https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
**********************************************************/

/* Recursion version */
int maxDepth(TreeNode* root) {
    if(root==nullptr)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return (l>r)?(l+1):(r+1);
}

/* Queue version */
int maxDepth(TreeNode* root) {
    queue<TreeNode *> q;
    int length = 0;
    TreeNode *temp;

    if(root==nullptr)
        return 0;

    q.push(root);
    while(!q.empty()) {
        length ++;
        int size = q.size();
        for(int i=0; i<size; i++) {
            temp = q.front();
            q.pop();
            if(temp->left!=nullptr)
                q.push(temp->left);
            if(temp->right!=nullptr)
                q.push(temp->right);
        }
    }

    return length;
}

/* Stack version */
int maxDepth(TreeNode* root) {
    stack<TreeNode *> st;
    TreeNode *p = root, *last = nullptr;
    int length = 0;

    while(p!=nullptr) {
        st.push(p);
        p = p->left;
    }
    while(!st.empty()) {
        p = st.top();
        if(p->left==nullptr && p->right==nullptr)
            length = max(length, (int)st.size());
        st.pop();
        if(p->right==nullptr || p->right==last)
           last = p;
        else {
            st.push(p);
            p = p->right;
            while(p!=nullptr) {
                st.push(p);
                p = p->left;
            }
        }
    }

    return length;
}

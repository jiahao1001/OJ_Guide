/****************************************************
* problem id : 94
* problem title : Binary Tree Inorder Traversal
* problem link : https://leetcode.com/problems/binary-tree-inorder-traversal/description/
*****************************************************/

/* Recursion version */
void inorderTraversal(vector<int> &ans, TreeNode *root) {
  if(root==nullptr)
    return;
  inorderTraversal(ans, root->left);
  ans.push_back(root->val);
  inorderTraversal(ans, root->right);
}

/* Non-recursion version */
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *p=root;

    while(p!=nullptr || !st.empty()) {
        if(p!=nullptr) {
            st.push(p);
            p = p->left;
        }
        else {
            p = st.top();
            st.pop();
            ans.push_back(p->val);
            p = p->right;
        }
    }

    return ans;
}

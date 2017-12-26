/******************************************************
* problem id : 145
* problem title : Binary Tree Postorder Traversal
* problem link : https://leetcode.com/problems/binary-tree-postorder-traversal/description/
*******************************************************/

/* Recursion version */
void postorderTraversal(vector<int> &ans, TreeNode *root) {
  if(root==nullptr)
    return;
  postorderTraversal(root->left);
  postorderTraversal(root->right);
  ans.push_back(root->val);
}

/* Non-recursion version */
vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *p=root, *last=nullptr;

    while(p!=nullptr) {
        st.push(p);
        p = p->left;
    }
    while(!st.empty()) {
        p = st.top();
        st.pop();
        if(p->right==nullptr || p->right==last) {
            ans.push_back(p->val);
            last = p;
        }
        else {
            st.push(p);
            p = p->right;
            while(p!=nullptr) {
                st.push(p);
                p = p->left;
            }
        }
    }

    return ans;
}

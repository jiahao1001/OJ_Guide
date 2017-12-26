/*****************************************************
* problem id : 144
* problem title : Binary Tree Preorder Traversal
* problem link : https://leetcode.com/problems/binary-tree-preorder-traversal/description/
******************************************************/

/* Recursion version */
void preorderTraversal(vector<int> &ans, TreeNode *root) {
  if(root==nullptr)
    return;
  ans.push_back(root->val);
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

/* Non-recursion version */
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode *> st;
    TreeNode *p=root;

    while(p!=nullptr || !st.empty()) {
        if(p!=nullptr) {
            ans.push_back(p->val);
            st.push(p);
            p = p->left;
        }
        else {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }

    return ans;
}

/***************************************************
* problem id : 538
* problem title : Convert BST to Greater Tree
* problem link : https://leetcode.com/problems/convert-bst-to-greater-tree/description/
****************************************************/

/* Recursion In-order traversal */
class Solution {
private:
    int cur_sum = 0;

public:
    void traversal(TreeNode *root) {
        if(root==nullptr)
            return;
        traversal(root->right);
        root->val += cur_sum;
        cur_sum = root->val;
        traversal(root->left);
    }

    TreeNode* convertBST(TreeNode* root) {
        traversal(root);
        return root;
    }
};

/* Non-recursion In-order traversal */
TreeNode* convertBST(TreeNode* root) {
    stack<TreeNode *> st;
    TreeNode *p = root;
    int sum = 0;

    while(p!=nullptr || !st.empty()) {
        if(p!=nullptr) {
            st.push(p);
            p = p->right;
        }
        else {
            p = st.top();
            st.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
    }

    return root;
}

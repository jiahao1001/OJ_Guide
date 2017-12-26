/*****************************************************
* problem id : 110
* problem title : Balanced Binary Tree
* problem link : https://leetcode.com/problems/balanced-binary-tree/description/
*****************************************************/

bool isBalanced(TreeNode* root) {
    if(root==nullptr)
        return true;
    int l = depth(root->left);
    int r = depth(root->right);
    return (abs(l-r)<=1) && isBalanced(root->left) && isBalanced(root->right);
}

int depth(TreeNode *root) {
    if(root==nullptr)
        return 0;
    int l = depth(root->left);
    int r = depth(root->right);
    return (l>r) ? (l+1) : (r+1);
}

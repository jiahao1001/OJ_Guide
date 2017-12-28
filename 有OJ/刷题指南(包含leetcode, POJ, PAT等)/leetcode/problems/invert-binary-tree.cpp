/********************************************************
* problem id : 226
* problem title : Invert Binary Tree
* problem link : https://leetcode.com/problems/invert-binary-tree/description/
*********************************************************/

TreeNode* invertTree(TreeNode* root) {
    if(root==nullptr)
      return nullptr;
    TreeNode *temp = root->left;
    root->left = root->right;
    root->right = temp;
    invertTree(root->left);
    invertTree(root->right);
    return root;
} 

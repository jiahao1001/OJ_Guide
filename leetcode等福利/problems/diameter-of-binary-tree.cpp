/******************************************************
* problem id : 543
* problem title : Diameter of Binary Tree
* problem link : https://leetcode.com/problems/diameter-of-binary-tree/description/
******************************************************/

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        return max(max(l,r), depth(root->left)+depth(root->right));
    }

    int depth(TreeNode *root) {
        if(root==nullptr)
            return 0;
        int l = depth(root->left);
        int r = depth(root->right);
        return (l>r)?(l+1):(r+1);
    }
}

/*************************************************************
* problem id : 572
* problem title : Subtree of Another Tree
* problem link : https://leetcode.com/problems/subtree-of-another-tree/description/
*************************************************************/

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s==nullptr && t==nullptr)
            return true;
        if(s==nullptr || t==nullptr)
            return false;
        return isSame(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSame(TreeNode *s, TreeNode *t) {
        if(s==nullptr && t==nullptr)
            return true;
        if(s==nullptr || t==nullptr)
            return false;
        if(s->val!=t->val)
            return false;
        return isSame(s->left, t->left)&&isSame(s->right, t->right);
    }
};

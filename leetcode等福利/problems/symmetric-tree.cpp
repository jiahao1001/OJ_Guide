/**************************************************************
* problem id : 101
* problem title Symmetric Tree
* problem link : https://leetcode.com/problems/symmetric-tree/description/
***************************************************************/

/* Recursion version */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
        return isSame(root->left, root->right);
    }

    bool isSame(TreeNode *t1, TreeNode *t2) {
        if(t1==nullptr && t2==nullptr)
            return true;
        if(t1==nullptr || t2==nullptr)
            return false;
        if(t1->val!=t2->val)
            return false;
        return isSame(t1->left, t2->right) && isSame(t1->right, t2->left);
    }
};

/* Non-recursion version */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> q1, q2;

        if(root==nullptr)
            return true;

        q1.push(root);
        q2.push(root);
        while(!q1.empty() && !q2.empty()) {
            TreeNode *p1 = q1.front();
            q1.pop();
            TreeNode *p2 = q2.front();
            q2.pop();
            if(p1==nullptr && p2==nullptr)
                continue;
            if(p1==nullptr || p2==nullptr)
                return false;
            if(p1->val!=p2->val)
                return false;
            q1.push(p1->left);
            q1.push(p1->right);
            q2.push(p2->right);
            q2.push(p2->left);
        }

        return true;
    }
};

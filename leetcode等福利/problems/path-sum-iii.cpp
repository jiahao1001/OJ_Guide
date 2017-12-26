/*********************************************************
* problem id : 437
* problem title : Path Sum III
* problem link : https://leetcode.com/problems/path-sum-iii/description/
*********************************************************/

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return 0;
        return sumUp(root, sum, 0)+pathSum(root->left, sum)+pathSum(root->right, sum);
    }

    int sumUp(TreeNode *root, int &sum, int pre) {
        if(root==nullptr)
            return 0;
        int cur = pre + root->val;
        return (cur==sum)+sumUp(root->left, sum, cur)+sumUp(root->right, sum, cur);
    }
};

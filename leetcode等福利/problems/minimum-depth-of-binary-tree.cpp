/***********************************************************
* problem id: 111
* problem title : Minimum Depth of Binary Tree
* problem link : https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
************************************************************/

/* Recursion method */
int minDepth(TreeNode *root) {
    if(root==nullptr)
        return 0;
    int l = minDepth(root->left);
    int r = minDepth(root->right);
    if(l==0 || r==0)
        return l+r+1;
    return min(l, r) + 1;
}

/* Level traversal method */
int run(TreeNode *root) {
    queue<TreeNode *> q;
    TreeNode *p;
    int height = 0;

    if(root==nullptr)
        return 0;

    q.push(root);
    while(!q.empty()) {
        height ++;
        int size = q.size();
        for(int i=0; i<size; i++) {
            p = q.front();
            q.pop();
            if(p->left==nullptr && p->right==nullptr)
                return height;
            if(p->left!=nullptr)
                q.push(p->left);
            if(p->right!=nullptr)
                q.push(p->right);
        }
    }

    return height;
}

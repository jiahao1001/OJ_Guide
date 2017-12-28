typedef struct BNode {
	int weight;
	struct BNode *left;
	struct BNode *right;
};

// 递归计算利用二叉链表存储的哈夫曼树值的算法
// 

int compute(BNode *root, int depth) {
	if (root->left == NULL && root->right == NULL) {
		return depth * weight;
	}
	else {
		return compute(root->left, depth + 1) + compute(root->right, depth + 1);
	}
}

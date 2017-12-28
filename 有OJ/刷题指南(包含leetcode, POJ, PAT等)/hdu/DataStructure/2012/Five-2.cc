// 2012 HDU Data Structure
// Five-2

typedef struct BiTNode {
	ElemType		data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

// 用于统计树中度为 2 的节点数
int num = 0;
void Count(BiTree T) {
	if (T != NULL) {
		if (T->lchild && T->rchild)
			num++;
		Count(T->lchild);
		Count(T->rchild);
	}
}
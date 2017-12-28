// 2012 HDU Data Structure
// Five-3

typedef struct BiTNode {
	TElemType		data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTNode *Next(BiTNode *p) {
	BiTNode *q = p->rchild;
	while (q->lchild != NULL) 
		q = q->lchild;
	return q;
}

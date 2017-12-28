typedef struct BiTNode {
	TelemType data;
	struct BiTNode *lchild, *rchild;
} *BiTree;

int depth[MaxSize];

void A8(BiTree T) {
	int front = 0, rear = 0;
	BTNode *que[MaxSize], *q;
	if (p != NULL) {
		rear = (rear + 1) % MaxSize;
		que[rear] = p;
		depth[rear] = 1;
		while (front != rear) {
			front = (front + 1) % MaxSize;
			q = que[front];
			if (q->lchild != NULL) {
				rear = (rear + 1) % MaxSize;
				que[rear] = q->lchild;
				depth[rear] = depth[front] + 1;
			}
			if (q->rchild != NULL) {
				rear = (rear + 1) % MaxSize;
				que[rear] = q->rchild;
				depth[rear] = depth[front] + 1;
			}
		}
	}
	cout << "The depth is : " << depth[front] << endl;
}


void A8(BiTree T) {
	int front = 0, rear = 0;
	BTNode *que[MaxSize], *q;
	if (p != NULL) {
		rear = (rear + 1) % MaxSize;
		que[rear] = p;
		int depth = 1;
		while (front != rear) {
			front = (front + 1) % MaxSize;
			q = que[front];
			if (q->lchild != NULL) {
				rear = (rear + 1) % MaxSize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL) {
				rear = (rear + 1) % MaxSize;
				que[rear] = q->rchild;
			}
			if (front == high) {
				high = rear;
				depth++;
			}
		}
	}
	cout << "The depth is : " << depth[front] << endl;
}

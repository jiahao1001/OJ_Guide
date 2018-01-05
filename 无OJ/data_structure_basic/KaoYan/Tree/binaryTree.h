#include <iostream>
#include <Stack>
#include <Queue>
using namespace std;

#ifndef MaxSize
#define MaxSize 200
#endif

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

BiTree createABiTree(void){
	BiTree result = (BiTree)malloc(sizeof(BiTNode));
	result->data = 500;
	FILE *f = fopen("../LinearTable/nums.data", "r");
	BiTNode *t, *p = result,*ancestor = result;
	int num;
	for (int i = 0; i < 100 - 1; ++i) {
		// num = getw(f);
		num = i * 9;
		t = (BiTNode *)malloc(sizeof(BiTNode));
		t->data = num;
		if (t->data > result->data) {
			p = result->rchild;
		} else {
			p = result->lchild;
		}

		while(p != NULL) {
			ancestor = p;
			if (t->data > p->data)
				p = p->rchild;
			else
				p = p->lchild;
		}
		if (ancestor->data < t->data) 
			ancestor->rchild = t;
		else
			ancestor->lchild = t;
	}
	fclose(f);

	return result;
}

void preOrder(BiTree T){
	if (T != NULL) {
		cout<<T->data<<" ";
		preOrder(T->lchild);
		preOrder(T->rchild);
	}
}

void inOrder(BiTree T){
	if (T != NULL) {
		inOrder(T->lchild);
		cout<<T->data<<" ";
		inOrder(T->rchild);
	}
}

void postOrder(BiTree T){
	if (T != NULL) {
		postOrder(T->lchild);
		postOrder(T->rchild);
		cout<<T->data<<" ";
	}
}

void postOrderNoRecurve(BiTree T){
	typedef struct {
		BiTNode *p;
		int rvisited;
	} SNode;
	SNode sn;
	BiTNode *pt = T;
	stack<SNode> s;

	while(pt){
		// 节点指针和节点访问信息放入堆栈
		sn.p = pt;
		sn.rvisited = 0;
		s.push(sn);
		pt = pt->lchild;
	}
	
	while(!s.empty()){
		// 栈顶元素
		sn = s.top();
		// 节点右孩子为空 或 右孩子已访问时，输出节点值
		if ( (sn.p->rchild == NULL) || (sn.rvisited)) {
			s.pop();
			cout<<sn.p->data<<" ";
		} else {
			// 节点右孩子非空且未被访问，应将右孩子及右孩子的左孩子放入堆栈,并设置当前节点右孩子已访问
			sn.rvisited = 1;
			s.pop();
			s.push(sn);
			pt = sn.p->rchild;
			while(pt != NULL){
				SNode temp;
				temp.p = pt; temp.rvisited = 0;
				s.push(temp);
				pt = pt->lchild;
			}
		}
	}
	cout<<endl;
}

void levelOrder(BiTree T){
	queue<BiTree> Q;
	BiTree p;
	Q.push(T);
	while(!Q.empty()){
		p = Q.front();
		Q.pop();
		cout<<p->data<<" ";
		if (p->lchild != NULL) 
			Q.push(p->lchild);
		if (p->rchild != NULL)
			Q.push(p->rchild);
	}
}

int heightOfT(BiTree T){
	if (T == NULL)
		return 0;
	int l = heightOfT(T->lchild);
	int r = heightOfT(T->rchild);
	if (l > r)
		return l + 1;
	else
		return r + 1;
}

// 并查集
int father[BUFSIZ];
int ranks[BUFSIZ];
void initUFSets(){
	for (int i = 0; i < BUFSIZ; ++i) {
		father[i] = i;
		ranks[i] = 0;
	}
}

int Find(int x)   //返回第Ｘ节点所属集合的根结点
{
	if (x != father[x])
		father[x] = Find(father[x]);
	return father[x];
}

void Union(int x,int y) {
	x = Find(x);
	y = Find(y);
	if (x == y)
		return ;
	if (ranks[x] > ranks[y])
		father[y] = x;
	else {
		if (ranks[x] == ranks[y])
			ranks[y] ++;
		father[x] = y;
	}
}

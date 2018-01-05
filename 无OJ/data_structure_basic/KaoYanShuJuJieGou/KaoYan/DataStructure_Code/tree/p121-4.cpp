/*
试给出二叉树自下而上，自右向左的层次遍历算法
-------
即层级遍历的同时放入栈
*/

typedef struct BiTNode{
  int data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void InvertLevel(BiTree bt)
{
  Stack s;
  Queue Q;
  if(bt!=NULL)
  {
    InitStack(s);
    InitQueue(Q);
    EnQueue(Q, bt);
    while (IsEmpty(Q) == false) {  //从上而下层次遍历
      DeQueue(Q, p);
      Push(S, p);   //此处放入栈进行逆向操作
      if(p->lchild)
          EnQueue(Q, p->lchild);
      if(p->rchild)
          EnQueue(Q, p->rchild);
    }
    while (IsEmpty(s)==false) {
      Pop(s, p);
      visit(p->data);
    }
  }
}

/*
编写后序遍历二叉树的非递归算法
*/

typedef struct BiTNode
{
  int data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

void PostOrder(BiTree T)
{
  InitStack(S);
  BiTree p=T, r=NULL;
  while (p||IsEmpty(S)) {
    if(p){
      push(S, p);
      p=p->lchild;  //先走到最左边
    }
    else{
      GetTop(S, p);
      if(p->rchild && p->rchild!=r)
      {
        p=p->rchild;
        push(S, p);
        p=p->lchild;
      }
      else
      {
        pop(S, p);
        visit(p->data);
        r=p;
        p=NULL;
      }
    }
  }
}

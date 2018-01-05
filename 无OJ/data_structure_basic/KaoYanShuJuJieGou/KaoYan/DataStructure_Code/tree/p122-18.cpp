/*
写出中序线索二叉树里查找指定结点在后序的前驱结点的算法
*/

typedef struct BiThrNode{
  int data;
  struct BiThrNode *lchild, *rchild;
  int ltag, rtag;
}BiThrNode, *BiThrTree;

BiThrTree InPostPre(BiThrTree t, BiThrTree p)
{
  BiThrTree q;
  if(p->rtag == 0)
      q = p->rchild;
  else if(p->ltag == 0)
      q = p->lchild;
  else if(p->lchild == NULL)
      q = NULL;
  else{
    while (p->ltag == 1 && p->lchild != NULL) {
          p = p->lchild;
    }
    if(p->ltag == 0)
        q = p->lchild;
    else
        q = NULL;
  }
    return q;
}

/*
对于树中每一个元素值为x的结点，删去以它为根的子树，并释放相应的空间
------------------------------------
采用后序遍历删除, 层次遍历查找
*/

void DeleteXTree(BiTree bt)
{
  if(bt)  //后序删除
  {
    DeleteXTree(bt->lchild);
    DeleteXTree(bt->rchild);
    free(bt);
  }
}

void Search(BiTree bt, int x)
{
  BiTree Q[];
  if(bt)
  {
    if(bt->data==x) //若根节点为x删除整棵树
    {
      DeleteXTree(bt);
      exit(0);
    }
    InitQueue(Q);//层次遍历
    EnQueue(Q, bt);
    while (!IsEmpty(Q)) {
      DeQueue(Q, p);
      if(p->lchild)
        if(p->lchild->data==x)
        {
          DeleteXTree(p->lchild);
          p->lchild = NULL;
        }
        else
          EnQueue(Q, p->lchild);
      if(p->rchild)
        if(p->rchild->data==x)
        {
          DeleteXTree(p->rchild);
          p->rchild = NULL;
        }
        else
          EnQueue(Q, p->rchild);
    }
  }
}

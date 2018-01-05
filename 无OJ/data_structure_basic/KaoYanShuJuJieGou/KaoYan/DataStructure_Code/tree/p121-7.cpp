/*
判别二叉树是否为完全二叉树
-----------------
采用层次遍历的算法，将所有结点加入队列，当遇到空结点，
查看其后是否有非空结点，若有，则不是完全二叉树
*/

bool IsComplete(BiTree T)
{
  InitQueue(Q);
  if(!T)
      return 1;  //空数为完全二叉树
  EnQueue(Q, T);
  while (!IsEmpty(Q)) {
    DeQueue(Q, p);
    if(p)  //此处不判断左右结点是否为空
    {
      EnQueue(p->lchild);
      EnQueue(p->rchild);
    }
    else    //结点为空时，检查其后是否有非空结点
        while (!IsEmpty(Q)) {
          DeQueue(Q, p);
          if(p)
              return 0;
        }
  }
  return 1;
}

/*
交换二叉树的左右子树
*/

void Swap(BiTree b)
{
  if(b)
  {
    Swap(b->lchild);
    Swap(b->rchild);
    BiTNode *temp=b->lchild;
    b->lchild=b->rchild;
    b->rchild=temp;
  }
}

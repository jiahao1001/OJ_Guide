/*
求树的高度的递归算法
*/

int Btdepth(BiTree T)
{
  if(T==NULL)
      return 0;
  ldep = Btdepth(T->lchild); //左子树高度
  rdep = Btdepth(T->rchild); //右子树高度
  if(ldep>rdep)
      return ldep + 1;
  else
      return rdep + 1;
}

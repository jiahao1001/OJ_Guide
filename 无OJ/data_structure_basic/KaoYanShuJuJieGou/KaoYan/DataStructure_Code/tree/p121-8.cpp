/*
计算一棵二叉树的双分枝结点个数
*/

int DsonNodes(BiTree b)
{
  if(b==NULL)
      return 0;
  else if(b->lchild!=NULL&&b->rchild!=NULL)
      return DsonNodes(b->lchild) +DsonNodes(rchild) +1;
  else
      return DsonNodes(b->lchild) + DsonNodes(rchild);
}

/*
试设计判断两棵二叉树是否相似的算法。所谓二叉树T1和T2相似。指的
是两者都是空的二叉树或者都只有一个根结点；或T1的左子树和T2的左子树
是相似的且T1的右子树和T2的右子树是相似的。
*/

int Similar(BiTree T1, BiTree T2)
{
  int leftS, rightS;
  if(T1==NULL && T2==NULL)
      return 1;
  else if(T1==NULL || T2==NULL)  //只有一树为空
      return 0;
  else{
    leftS = Similar(T1->lchild, T2->lchild);
    rightS = Similar(T1->rchild, T2->rchild);
    return leftS && rightS;
  }
}

/*
二叉树的带权路径长度WPL时二叉树中所有叶结点的带权路径长度之和。
给定一棵二叉树T,采用二叉链表存储，结点结构为left-weight-right
其中叶节点的weight域保存该结点的非负权值。设root为指向T的根节点
的指针，设计求T的WPL的算法
-----------------------
二叉树的带权路径长度为每个叶结点的深度与权值之积的总和
采用先序遍历递归的方法
*/

typedef struct BiTNode{
  int weight;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

int WPL(BiTree root)
{
  return wpl_PreOrder(root, 0);
}

int wpl_PreOrder(BiTree root, int deep)
{
  static int wpl=0;
  if(root->lchild ==NULL && root->rchild == NULL) //叶结点
      wpl += deep * root->weight;
  if(root->lchild != NULL)
      wpl_PreOrder(root->lchild, deep+1);
  if(root->rchild != NULL)
      wpl_PreOrder(root->rchild, deep+1);
  return wpl;
}

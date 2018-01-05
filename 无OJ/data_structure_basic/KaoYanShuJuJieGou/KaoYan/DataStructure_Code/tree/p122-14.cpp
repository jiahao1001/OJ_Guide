/*
求二叉树的宽度
------------
采用层次遍历的方法求出所有结点的层次，并将所有结点和对应的层次放入一个队列。
然后通过扫描队列求出各层的结点总数，最大的层结点总数即为二叉树的宽度
*/

#define MaxSize 50

typedef struct BiTNode{
  int data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct{
  BiTree data[MaxSize];
  int level[MaxSize];
  int front, rear;
}Qu;

int BTWidth(BiTree b)
{
  BiTree p;
  int k, max, i, n;
  Qu.front = Qu.rear = -1;
  Qu.rear++;
  Qu.data[Qu.rear] = b; //根结点指针入队
  Qu.level[Qu.rear] = 1; //根结点层次为1
  while (Qu.front < Qu.rear) {
    Qu.front++;  //出队
    p=Qu.data[Qu.front]; //出队结点
    k = Qu.level[Qu.front]; //出队结点的层次
    if(p->lchild != NULL)
    {
      //左孩子进队
      Qu.rear++;
      Qu.data[Qu.rear] = p->lchild;
      Qu.level[Qu.rear] = k+1;
    }
    if(p->rchild != NULL)
    {
      //右孩子结点入队
      Qu.rear++;
      Qu.data[Qu.rear] = p->rchild;
      Qu.level[Qu.rear] = k+1;
    }
  }
  max = 0; i =0;  //max保存同一层最多的结点个数
  k = 1;  //k表示从第一层开始查找
  while (i <= Qu.rear) {
    n = 0;    //n统计第k层的结点个数
    while (i<=Qu.rear && Qu.level[i] == k) {
      n++;
      i++;
    }
    k=Qu.level[i];
    if(n>max)   max = n;
  }
  return max;
}

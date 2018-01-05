/*
非递归算法求二叉树高度
---------
采用层次遍历算法，设置变量记录当前层数
*/

int Btdepth(BiTree T)
{
  if(!T)
      return 0;
  int front=-1, rear=-1;
  int last=0, level=0;    //last指向下一层第一个结点位置
  BiTree Q[MaxSize];   //设置队列
  Q[++rear] = T;   //根结点入队
  BiTree p;
  while (front<rear) {  //队不空时循环
    p=Q[++front];  //队列元素出队
    if(p->lchild)
        Q[++rear]=p->lchild;
    if(p->rchild)
        Q[++rear]=p->rchild;
    if(front == last)  //处理该层最右结点
    {
      level++;
      last=rear;  //last指向下层
    }
  }
  return level;
}

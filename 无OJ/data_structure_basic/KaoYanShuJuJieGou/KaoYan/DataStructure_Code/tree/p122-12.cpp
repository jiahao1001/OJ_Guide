/*
在二叉树中查找值为x的结点，编写算法打印值为x的结点的所有祖先，x<=1
-------------------------
采用非递归后序遍历，最后访问根结点，当访问到值为x的结点时，栈中所有元素均为其祖先
*/

typedef struct{
  BiTree t;
  int tag;
}stack;  //tag=0表示左子女被访问，tag=1表示右子女被访问

void Search(BiTree bt, int x)
{
  stack s[];
  int top=0;
  while (bt!=NULL||top>0) {
    while (bt!=NULL && bt->data != x) {
      s[++top].t = bt;
      s[top].tag = 0;
      bt=bt->lchild;  //沿左分支向下
    }
    if(bt->data == x)
    {
      printf("所查结点的所有祖先结点的值为:\n"); //找到x
      for (int i=1; i<=top; i++)
      {
          printf("%d ",s[i].t->data);
      }
      exit(1);
    }
    while (top!=0 && s[top].tag == 1) {
      top--;
    }
    if(top!=0){
      s[top].tag = 1;
      bt=s[top].t->rchild;
    }
  }
}

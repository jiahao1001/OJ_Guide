/*
p q为指向二叉树中任意两个结点的指针，编写算法找到p和q最近公共祖先
------------------------
采用后序非递归算法，当访问到某结点时，栈中所有元素都为该结点祖先
假设p在左边，后序遍历必然先遍历到p，栈中元素均为p的祖先。
将栈复制到另一辅助栈中，继续遍历到结点q，将栈中元素从栈顶开始逐个去匹配
第一个匹配的元素就是结点p和q的最近公共祖先
*/

typedef struct BiTNode{
  int data;
  struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

typedef struct{
    BiTree t;
    int tag;  //tag=0表示左子女被访问,tag=1表示右子女被访问
}stack;

stack s[], s1[];

BiTree Ancestor(BiTree root, BiTNode *p, BiTNode *q)
{
  int top=0, top1;
  BiTNode *bt=root;
  while (bt!=NULL || top>0) {
    while (bt!=NULL && bt!=p && bt!=q)
      while (bt!=NULL) {
        s[++top].t = bt;
        s[top].tag = 0;
        bt=bt->lchild;
      }   //沿分支左下
      while (top!=0 && s[top].tag == 1) {
        //假定p在q的左侧，遇到p时，栈中元素均为p的祖先
        if(s[top].t == p){
          for(int i=1; i<=top; i++)
              s1[i] = s[i]  //保存到辅助栈中
              top1 = top;
        }
        if(s[top].t == q)
        {
          for(int i=top; i>0; i--)
              for(int j = top1; j>0; j--)
                  if(s1[j].t == s[i].t)
                      return s[i].t  //最近公共祖先以找到
        }
        top--; //退栈
      }
      if(top!=0)
      {
        s[top].tag = 1;
        bt = s[top].t->rchild;
      }
  }
  return NULL;
}

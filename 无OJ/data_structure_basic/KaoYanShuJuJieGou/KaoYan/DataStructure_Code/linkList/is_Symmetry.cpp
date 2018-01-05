/*设计一个算法用于判断带头结点的循环双链表是否对称*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
  struct LNode *pre;
}LNode, *LinkList;

LinkList CreateList()
{
  LinkList l =(LinkList)malloc(sizeof(LNode));
  LNode *s, *p=l;
  int x;
  l->next = NULL;
  scanf("%d",&x);
  while (x != -1) {
    s=(LNode*)malloc(sizeof(LNode));
    s->data = x;
    p->next = s;
    s->pre=p;
    p=s;
    scanf("%d",&x);
  }
  p->next = l;
  l->pre = p;
  return l;
}

int IsSymmetry(LinkList &l)
{
  LNode *p=l->next,*q=l->pre;
  while (p!=q && q->next != p) {
    if(p->data == q->data)
    {
      p=p->next;
      q=q->pre;
    }
    else
        return 0;
  }
  return 1;
}

int main()
{
  LinkList l = CreateList();
  printf("%d\n",IsSymmetry(l));
  return 0;
}

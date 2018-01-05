/*给定两个单链表，编写算法找出两个链表的公共结点
此代码并不能运行 ，因为输入的链表并没有确定相同后继结点
主要观察代码思想*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList(int n)
{
  int x;
  LinkList L=(LinkList)malloc(sizeof(LNode));
  L->next=NULL;
  LNode *s, *p=L;
  printf("请输入第%d个链表:\n", n);
  scanf("%d",&x);
  while (x != -1) {
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    p->next = s;
    p = s;
    scanf("%d",&x);
  }
  p->next = NULL;
  return L;
}

int Length(LinkList &l)
{
  //带头结点
  int num=0;
  while (l->next != NULL) {
    num++;
    l=l->next;
  }
  return num;
}

int findSameNode(LinkList &l1, LinkList &l2)
{
  LinkList longList, shortList;
  int len1=Length(l1);
  int len2=Length(l2);
  if(len1>len2)
  {
    dist=len1-len2;
    longList = l1;
    shortList = l2;
  }
  else
  {
    dist=len2-len1;
    longList = l2;
    shortList = l1;
  }
  while (dist--) {
    longList=longList->next;
  }
  while (longList!=NULL) {
    if(longList == shortList)
      return longList->data;
    else
    {
      longList=longList->next;
      shortList=shortList->next;
    }
  }
  return 0;
}

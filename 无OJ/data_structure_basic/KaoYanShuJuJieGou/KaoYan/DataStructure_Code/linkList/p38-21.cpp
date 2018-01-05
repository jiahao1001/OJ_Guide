/*
一个单链表只给出头指针，设计一个高效的算法，查找链表中
倒数第k个位置上的结点。若查找成功，输出其值，符合输出0
*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList()
{
  int x;
  LinkList l=(LinkList)malloc(sizeof(LNode));
  LNode *s, *p = l;
  l->next=NULL;
  scanf("%d",&x);
  while (x!=-1) {
    s=(LNode*)malloc(sizeof(LNode));
    s->data = x;
    p->next = s;
    p=s;
    scanf("%d",&x);
  }
  p->next=NULL;
  return l;
}

int Find(LinkList &l, int x)
{
  //定义两个指针，一个先找到第x个结点，第二个才从开始走
  LNode *p, *q;
  p=q=l;
  while (x--) {
    p=p->next;
     }
     while (p!=NULL) {
       p=p->next;
       q=q->next;
     }
if(!q)
    return 0;
else
    return q->data;
}

int main()
{
  LinkList l=CreateList();
  int x;
  scanf("%d",&x);
  while (x!=-1) {
    printf("%d\n",Find(l, x));
    scanf("%d",&x);
  }
  return 0;
}

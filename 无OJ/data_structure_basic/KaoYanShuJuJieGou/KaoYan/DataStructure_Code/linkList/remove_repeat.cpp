/*在一个递增有序的线性表中，有数值相同的元素存在。若存储方式为单链表，
设计算法去掉数值相同的元素，使表中不再有重复的元素。*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList()
{
  int x;
  LinkList l = (LinkList)malloc(sizeof(LNode));
  LNode *s, *p=l;
  l->next = NULL;
  scanf("%d",&x);
  while (x != -1) {
    s=(LNode*)malloc(sizeof(LNode));
    p->next=s;
    p=s;
    scanf("%d",&x);
  }
  p->next=NULL;
  return l;
}

void Print(LinkList &l)
{
  if(l==NULL || l->next==NULL)
  {
    printf("null\n");
    return;
  }
  l=l->next;
  while (l!=NULL) {
    printf("%d ",l->data);
    l=l->next;
  }
}

void Remove_repeat(LinkList &l)
{
  LNode *p=l->next, *q;
  while (p->next != NULL) {
    q=p->next;
    if(q->data==p->data)
    {
      p->next=q->next;
      free(q);
    }
    else
      p=p->next;
  }
}

int main()
{
  LinkList l = CreateList();
  Remove_repeat(l);
  Print(l);
  return 0;
}

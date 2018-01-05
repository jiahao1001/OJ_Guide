/*
设有一个带头结点的循环单链表，其结点值均为正整数。设计一个算法，反复找出单链
表中最小的结点并输出，然后将该结点从中删除，直到单链表为空为止，再删除头结点。
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
  LNode *s, *p=l;
  l->next=NULL;
  scanf("%d",&x);
  while (x!=-1) {
    s=(LNode*)malloc(sizeof(LNode));
    s->data = x;
    p->next = s;
    p=s;
    scanf("%d",&x);
  }
  p->next = l;
  return l;
}

void Delete_Min(LinkList &l)
{
  LNode *min, *pre, *p, *minpre;
  while (l->next !=l) {
     p=l->next;
     pre=l;
     min=p;
     minpre=pre;
     while (p!=l) {
       if(p->data <min->data)
       {
         min = p;
         minpre=pre;
       }
       pre=p;
       p=p->next;
     }
     printf("%d ",min->data);
     minpre->next = min->next;
     free(min);
  }
  free(l);
}

int main()
{
  LinkList l=CreateList();
  Delete_Min(l);
  return 0;
}

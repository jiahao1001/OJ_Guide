/*
有一个带头结点的单链表，设计一个算法使其元素递增有序
此算法时间复杂度O(N**2)
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
  LinkList L=(LinkList)malloc(sizeof(LNode));
  L->next=NULL;
  LNode *s, *p=L;
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

void Print(LinkList &l) {
  if(l == NULL || l->next==NULL)
  {
     printf("Sorry, your link is null.\n");
     return;
   }
  l = l->next;
  while (l != NULL) {
    printf("%d ",l->data);
    l=l->next;
  }
}

void Order(LinkList &l)
{
  //递增排序
    LNode *p=l->next, *pre;
    LNode *r=p->next;//r保持p后继指针，防止断链
    p->next=NULL;
    p=r;
    while(p!=NULL)
    {
        r=p->next;
        pre=l;
        while(pre->next!=NULL&&pre->next->data<p->data)
        {
            pre=pre->next;
        }
        p->next=pre->next;
        pre->next=p;
        p=r;
    }
}

int main()
{
    LinkList l=CreateList();
    Order(l);
    Print(l);
    return 0;
}

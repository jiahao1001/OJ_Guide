/*试编写算法将带头结点的单链表就地逆置
所谓就地指空间复杂度为O(1)*/

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

void Reverse(LinkList &l)
{
  //头插法插入即可逆置
  LNode *p, *r=l;
  r=r->next;
  while (r->next !=NULL) {
    /* code */
    p=r->next;
    r->next=p->next;
    p->next=l->next;
    l->next=p;
  }
}

int main()
{
  LinkList l=CreateList();
  Reverse(l);
  Print(l);
  return 0;
}

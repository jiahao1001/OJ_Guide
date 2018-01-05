/*设L为带头结点的单链表，编写算法实现从尾到头反向输出每个结点的值*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList()
{
  LinkList l = (LinkList)malloc(sizeof(LNode));
  l->next =NULL;
  LNode *s, *p=l;
  int x;
  scanf("%d",&x);
  while (x != -1) {
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    p->next = s;
    p = s;
    scanf("%d",&x);
  }
  p->next = NULL;
  return l;
}

void Reverse_Print(LinkList &l)
{
  if(l->next !=NULL)
    Reverse_Print(l->next);
  printf("%d ", l->data);
}

int main()
{
  LinkList l = CreateList();
  if(l->next == NULL)
    printf("This is a empty list\n");
  else
    Reverse_Print(l->next);
  return 0;
}

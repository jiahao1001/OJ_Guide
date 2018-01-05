/*给定一个带表头结点的单链表，设head为头指针，写出算法：
按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间*/

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
  while (x!=-1) {
    s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    p->next=s;
    p=s;
    scanf("%d",&x);
  }
  p->next =NULL;
  return L;
}

void Print(LinkList &l)
{
  if(l==NULL || l->next==NULL)
  {
    printf("Sorry, your link is null\n");
    return;
  }
  l=l->next;
  while (l != NULL) {
    printf("%d ",l->data);
    l=l->next;
  }
}

void OrderDelete(LinkList &l)
{
  LNode *pre, *p, *u;
  //依次删除链表中最小的元素
  while (l->next != NULL) {
    pre=l;
    p=pre->next;
    while (p->next!=NULL) {
      if(p->next->data<pre->next->data)
        pre=p;
      p=p->next;
    }
  printf("%d ",pre->next->data);
  u=pre->next;
  pre->next=u->next;
  free(u);
  }
  free(l);
}

int main()
{
  LinkList l=CreateList();
  OrderDelete(l);
  return 0;
}

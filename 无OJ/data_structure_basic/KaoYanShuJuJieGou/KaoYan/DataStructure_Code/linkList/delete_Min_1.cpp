/*
试编写在带头结点的单链表中删除一个最小值结点的高效算法
(假设此最小值结点唯一）
方法一
*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList()
{
  LinkList l = (LinkList)malloc(sizeof(LNode));
  l->next=NULL;
  LNode *s, *p=l;
  int x;
  scanf("%d",&x);
  while (x!=-1) {
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    p->next=s;
    p=s;
    scanf("%d",&x);
  }
  p->next=NULL;
  return l;
}

void Print(LinkList &l)
{
  if(l->next == NULL)
  {
    printf("这是一个空链表\n");
    return;
  }
  l=l->next;
  while (l!=NULL) {
    printf("%d ",l->data);
    l=l->next;
  }
}

void DeleteMin(LinkList &l)
{
  int temp;
  LNode *l_pre=l, *min_pre=l, *min, *r=l;
  l=l->next;
  min=l;
  temp = l->data;
  while (l!=NULL) {
    if(l->data<temp)
    {
      min_pre=l_pre;
      min=l;
      temp=l->data;
      l_pre=l;
      l=l->next;
    }
    else{
      l_pre=l;
      l=l->next;
    }
  }
  //删除
  min_pre->next=min->next;
  free(min);
  l=r;
}

int main()
{
  LinkList l = CreateList();
  DeleteMin(l);
  Print(l);
  return 0;
}

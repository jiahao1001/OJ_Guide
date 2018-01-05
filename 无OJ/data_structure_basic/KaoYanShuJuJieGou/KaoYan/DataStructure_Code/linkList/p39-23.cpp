/*
用单链表保存m个整数，其中data为正整数,且小于N。现设计一个高效的算法，
对于链表中data的绝对值相等的结点，仅保留第一次的结点而删除其余绝对值
相等的结点
*/

#include <stdio.h>
#include <malloc.h>

#define N 50

typedef struct LNode{
  int data;
  LNode *next;
}LNode, *LinkList;

LinkList CreateList()
{
  int x;
  LinkList l=(LinkList)malloc(sizeof(LNode));
  l->next=NULL;
  LNode *s, *p=l;
  scanf("%d",&x);
  while (x!=-1) {
    s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    p->next=s;
    p=s;
    scanf("%d",&x);
  }
  p->next=NULL;
  return l;
}

void Delete_(LinkList &l)
{
  int data[N+1]={0}, m;
  LNode *p=l, *s;
  while (p->next!=NULL) {
    /* code */
    m=p->next->data>0?p->next->data:-p->next->data;
    if(data[m]==0)
    {
      data[m]=1;
      p=p->next;
    }
    else{
      s=p->next;
      p->next = s ->next;
      free(s);
    }
  }
//  return l
}

void Print(LinkList &l)
{
  if (!l || !l->next) {
    printf("null\n");
    return;
  }
  l=l->next;
  while (l) {
    printf("%d ",l->data);
    l=l->next;
  }
}

int main()
{
  LinkList l = CreateList();
  Delete_(l);
  Print(l);
  return 0;
}

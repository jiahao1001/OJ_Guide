/*设A和B是两个单链表（带头结点），其中元素递增有序。设计一个算法从A和B中
的公共元素产生单链表C，要求不破坏AB的结点*/


#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList(int n)
{
  int x;
  LinkList l = (LinkList)malloc(sizeof(LNode));
  l->next = NULL;
  LNode *s, *p=l;
  printf("请输入第%d个链表的值:",n);
  scanf("%d",&x);
  while (x != -1) {
    /* code */
    s=(LNode*)malloc(sizeof(LNode));
    s->data= x;
    p->next = s;
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

LinkList MergeTheSame(LinkList &l1, LinkList &l2)
{
  LinkList l = (LinkList)malloc(sizeof(LNode));
  LNode *p1=l1->next, *p2=l2->next,  *s, *p=l;
  p->next = NULL;
  while (p1!=NULL && p2!=NULL) {
    /* code */
    if(p1->data == p2->data)
    {
      s=(LNode*)malloc(sizeof(LNode));
      s->data = p1->data;
      p->next=s;
      p=s;
      p1=p1->next;
      p2=p2->next;
    }
    else if(p1->data <p2->data)
    {
      p1=p1->next;
    }
    else
      p2=p2->next;
  }
  p->next = NULL;
  return l;
}

int main()
{
  LinkList l1 = CreateList(1);
  LinkList l2 = CreateList(2);
  LinkList l = MergeTheSame(l1, l2);
  Print(l);
  return 0;
}

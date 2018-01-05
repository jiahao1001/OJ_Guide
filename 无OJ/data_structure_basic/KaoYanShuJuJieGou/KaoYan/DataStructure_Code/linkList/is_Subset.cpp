/*
两个整数序列存入两个单链表中，判断其中一个是否为另一个的子序列
*/

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
  if(l==NULL || l->next == NULL)
  {
    printf("null\n");
    return;
  }
  l=l->next;
  while (l) {
    /* code */
    printf("%d ",l->data);
    l=l->next;
  }
}

int IsSubset(LinkList &l1, LinkList &l2)
{
  LNode *p1=l1->next, *p2=l2->next;
  LNode *s=p1;
  //int isSub=0;
  while (p1 && p2) {
    if(p1->data == p2->data)
    {
      p1=p1->next;
      p2=p2->next;
    }
    else{
      s=s->next;
      p1=s;
      p2=l2->next;
    }
  }
  if(p2==NULL)
      return 1;
  else
      return 0;
}

int main()
{
  LinkList l1=CreateList(1);
  LinkList l2=CreateList(2);
  printf("%d\n",IsSubset(l1, l2));
  return 0;
}

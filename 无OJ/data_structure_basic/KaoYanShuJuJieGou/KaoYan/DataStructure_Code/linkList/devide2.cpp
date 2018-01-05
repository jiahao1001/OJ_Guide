/*设C={a1,b1,a2,b2......an,bn}为线性表，采用带头结点的hc单链表
存放，设计一个就地算法，将其拆分为两个线性表使得A={a1,a2,a3,a4,...},
B={bn,...b2,b1}*/

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
  p->next = NULL;
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

void Devide2(LinkList &l)
{
  LinkList l1=(LinkList)malloc(sizeof(LNode));
  LinkList l2 = (LinkList)malloc(sizeof(LNode));
  LNode *p1=l1, *p2=l2, *s;
  p2->next=NULL;
  int n=0;
  s=l->next;
  while (s != NULL) {
    l=s;
    s=l->next;
    n++;
    if(n%2!=0)
    {
      p1->next = l;
      p1=l;
    }
    else{
      //头插法即可
      l->next=p2->next;
      p2->next=l;
    }
  }
  p1->next=NULL;

  //输出
  printf("奇数链表: ");
  Print(l1);
  printf("\n");
  printf("偶数链表: ");
  Print(l2);
}


int main()
{
  LinkList l = CreateList();
  Devide2(l);
  return 0;
}

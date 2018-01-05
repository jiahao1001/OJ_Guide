/*将一个带头结点的单链表A分解为两个带头结点的单链表A和B
使得A表中含有原表中序号为奇数的元素，而B表中含有原表中序号
为偶数的元素，且保持其相对顺序不变。*/

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

void Devide(LinkList &l)
{
  LinkList l1=(LinkList)malloc(sizeof(LNode));
  LinkList l2=(LinkList)malloc(sizeof(LNode));
  LNode *p1=l1, *p2=l2;
  int n=0;
  while (l->next != NULL) {
    l=l->next;
    n++;
    if(n%2!=0)
    {
      //s=(LNode*)malloc(sizeof(LNode));
      p1->next = l;
      p1=l;
    }
    else
    {
      //s=(LNode*)malloc(sizeof(LNode));
      p2->next = l;
      p2=l;
    }
  }
  p1->next = NULL;
  p2->next = NULL;

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
  Devide(l);
  return 0;
}

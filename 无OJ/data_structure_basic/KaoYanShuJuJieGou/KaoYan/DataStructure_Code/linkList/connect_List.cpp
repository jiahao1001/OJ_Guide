/*
有两个循环单链表，链表头指针分别为h1和h2，编写一个函数将链表h2
链接到链表h1之后，要求链接后的链表仍保持循环链表形式
*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList(int n)
{
  LinkList l =(LinkList)malloc(sizeof(LNode));
  int x;
  LNode *s, *p=l;
  p->next=NULL;
  printf("输入第%d个链表的值:",n);
  scanf("%d",&x);
  while (x!=-1) {
    s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    p->next = s;
    p=s;
    scanf("%d",&x);
  }
  p->next=l;
  return l;
}

void Print(LinkList &l)
{
  if(l==NULL || l->next == NULL)
  {
    printf("null\n");
    return;
  }

  LNode *p=l->next;
  while (p!=l) {
    /* code */
    printf("%d ",p->data);
    p=p->next;
  }
}

void Connect(LinkList &l1, LinkList &l2)
{
  LNode *p=l1->next;
  while (p->next != l1) {
    p=p->next;
  }
  p->next = l2->next;
  p=l2->next;
  while (p->next != l2) {
    p=p->next;
  }
  p->next = l1;
}

int main()
{
  LinkList l1=CreateList(1);
  LinkList l2=CreateList(2);
  Connect(l1, l2);
  Print(l1);
  return 0;
}

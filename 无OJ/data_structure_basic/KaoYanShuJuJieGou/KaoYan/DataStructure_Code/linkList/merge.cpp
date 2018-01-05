/*将两个按元素值递增次序排列的线性表，均以单链表形式存储。
请编写算法将两个链表归并为一个按元素值递减次序排列的单链表，
并要求利用原来两个单链表的结点存放归并后的单链表*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;

LinkList CreateList(int n)
{
  int x;
  LinkList l =(LinkList)malloc(sizeof(LNode));
  l->next=NULL;
  LNode *s, *p=l;
  printf("请输入第%d个链表的值:",n);
  scanf("%d",&x);
  while (x!=-1) {
    /* code */
    s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    p->next=s;
    p=s;
    scanf("%d",&x);
  }
  p->next = NULL;
  return l;
}
/*将两个递增合并为一个递减,在依次比较时头插法*/
LinkList Merge(LinkList &l1, LinkList &l2)
{
  LinkList l =(LinkList)malloc(sizeof(LNode));
  l->next=NULL;
  LNode *p1=l1->next, *p2=l2->next, *q=l;
  while (p1!=NULL && p2!=NULL) {
    if(p1->data < p2->data)
    {
      q->next = p1;
      q=p1;
      p1=p1->next;
    }
    else{
      q->next = p2;
      q=p2;
      p2=p2->next;
    }
  }
  while(p1!=NULL)
  {
    q->next=p1;
    q=p1;
    p1=p1->next;
  }
  while (p2!=NULL) {
    q->next=p2;
    q=p2;
    p2=p2->next;
  }
  q->next = NULL;
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
    /* code */
    printf("%d ",l->data);
    l=l->next;
  }
}

int main()
{
  LinkList l1 = CreateList(1);
  LinkList l2=CreateList(2);
  LinkList l =Merge(l1, l2);
  Print(l);
  return 0;
}

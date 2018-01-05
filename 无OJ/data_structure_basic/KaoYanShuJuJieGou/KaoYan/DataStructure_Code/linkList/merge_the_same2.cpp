/*求两递增链表的交集，其余结点全部释放*/

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

LinkList MergeTheSame2(LinkList &l1, LinkList &l2)
{
  LinkList l=(LinkList)malloc(sizeof(LNode));
  LNode *p1=l1->next, *p2=l2->next, *p=l, *u;
  p->next = NULL;
  while (p1!=NULL && p2!=NULL) {
    if(p1->data==p2->data)
    {
      p->next = p1;
      p=p1;
      p1=p1->next; //只需指向下一个，所有剩余都需要删除
      u=p2;
      p2=p2->next;
      free(u);
    }
    else if(p1->data < p2->data)
    {
      u=p1;
      p1=p1->next;
      free(u);
    }
    else{
      u=p2;
      p2=p2->next;
      free(u);
    }
  }
  while (p1) {
    u=p1;
    p1=p1->next;
    free(u);
  }
  while (p2) {
    u=p2;
    p2=p2->next;
    free(u);
  }
  p->next = NULL;
  free(l1);
  free(l2);
  return l;
}

int main()
{
  LinkList l1=CreateList(1);
  LinkList l2 = CreateList(2);
  LinkList l = MergeTheSame2(l1, l2);
  Print(l);
  return 0;
}

/*设在一个带表头结点的单链表中所有元素结点的数据值无序
，试编写一个函数，删除表中所有介于给定两个值（作为函数
参数给出）之间的元素*/

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
  while (x != -1) {
    s = (LNode*)malloc(sizeof(LNode));
    s->data = x;
    p->next = s;
    p = s;
    scanf("%d",&x);
  }
  p->next = NULL;
  return L;
}

void Delete_X2Y(LinkList &l, int x, int y)
{
  LNode *s, *p=l, *t;
  s=p->next;
  while (s != NULL) {
    if(s->data <=y && s->data>=x)
    {
      t=s;
      s=s->next;
      p->next=s;
      free(t);
    }
    else
    {
      p=s;
      s=s->next;
    }
  }
}

void Print(LinkList &l) {
  if(l == NULL || l->next==NULL)
  {
     printf("Sorry, your link is null.\n");
     return;
   }
  l = l->next;
  while (l != NULL) {
    printf("%d ",l->data);
    l=l->next;
  }
}

int main()
{
  LinkList l=CreateList();
  int a, b;
  printf("请输入取值范围:");
  scanf("%d%d",&a, &b);
  Delete_X2Y(l, a, b);
  Print(l);
  return 0;
}

/*带头结点,且此处不采用递归方式去删除链表中某一值*/

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

void DeleteX(LinkList &L, int x)
{
  LNode *p, *q=L, *r=L;
  L = L->next;
  while (L != NULL) {
    if(L->data != x)
       {
         q = L;
         L = L->next;
       }
    else{
      p = L;
      q->next = p->next;
      L = p->next;
      free(p);
    }
  }
  L = r;  //最后记得将指针重新指向开始
}


int main()
{
  LinkList l = CreateList();
  DeleteX(l, 3);
  Print(l);
  return 0;
}

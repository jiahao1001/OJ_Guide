/*设计一个递归算法，删除不带头结点的单链表L中所有值为x的结点*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *next;
}LNode, *LinkList;



//尾插法
LinkList CreateList()
{
  LNode *s, *p;
  int x;
  LinkList L=NULL;
  L = (LinkList)malloc(sizeof(LNode));
  L->next =NULL;
  p = L;
  scanf("%d",&x);
  while (x != -1) {
    p->data = x;
    s = (LNode*)malloc(sizeof(LNode));
    //s->data = x;
    p->next = s;
    p = s;
    scanf("%d", &x);
  }
  p->next = NULL;
  return L;
}

//C++中才具有引用
void DeleteX(LinkList &L, int x)
{
  LNode *p;
  if(L == NULL)
      return;
  if(L->data == x)
  {
    p = L;
    L = L->next;
    free(p);
    DeleteX(L, x);
  }
  else
      DeleteX(L->next, x);
}

void Print(LinkList &l) {
  while (l->next != NULL) {
    printf("%d ",l->data);
    l = l->next;
  }
}

int main()
{
  LinkList l=CreateList();
  DeleteX(l, 3);
  Print(l);
  return 0;
}


// 头插法建立单链表

/*LinkList CreateList()
{
  LNode *s, *p;
  int x;
  LinkList L = NULL;
  L = (LinkList)malloc(sizeof(LNode)); //创建头结点
  p = L;
  L->next=NULL;
  scanf("%d", &x); //输入结点的值
  while (x!=-1) {
    s=(LNode*)malloc(sizeof(LNode));
    s->data=x;
    s->next=L->next;  //头插法
    L->next=s;
    scanf("%d", &x);
  }
  return p;
}
*/

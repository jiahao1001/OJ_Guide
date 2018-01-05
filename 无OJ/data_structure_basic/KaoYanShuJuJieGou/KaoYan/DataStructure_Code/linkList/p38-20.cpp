/*
设头指针为l的带有表头结点的非循环双向链表，其每个结点中除有pred,data
,next之外，还有一个访问频度域freq，在链表被启用前，其值均初始化为0.每
当在链表中进行一次locate(l, x)运算时，令元素值为x的结点中freq域的值增1.
并使此链表中结点保持按访问频度非增的顺序排列，同时最近访问的结点排在频度相同
的结点的前面，以便使频繁访问的结点总是靠近表头。试编写符合上述要求的locate(l,x)
运算的算法，该运算为函数过程，返回找到结点的地址。
*/

#include <stdio.h>
#include <malloc.h>

typedef struct LNode{
  int data;
  struct LNode *pred;
  struct LNode *next;
  int freq;
}LNode, *LinkList;

LinkList CreateList()
{
  int x;
  LinkList l=(LinkList)malloc(sizeof(LNode));
  LNode *s, *p=l;
  l->pred = l->next = NULL;
  scanf("%d",&x);
  while (x!=-1) {
    s =(LNode *)malloc(sizeof(LNode));
    s->freq= 0;
    s->data= x;
    p->next = s;
    s->pred = l;
    p=s;
    scanf("%d",&x);
  }
  p->next = NULL;
  return l;
}

LinkList Locate(LinkList &l, int x)
{
  //先查找数据x， 查找成功后结点的访问频度加1
  //最后将该结点按频度递减插入链表中适当位置
  LNode *p=l->next, *q;
  while (p&&p->data!=x) {
    p=p->next;  //找到位置
  }
  if(!p)
  {
    printf("不存在值为%d的结点\n",x);
    exit(0);
  }
  else{
    p->freq++; //频度加1
    //将此结点取下并不断链
    p->next-pred = p->pred;
    p->pred->next = p->next;
    //查找p结点的插入位置
    q=p->pred;
    while (q!=l&&q->freq<=p->freq) {
      q=q->freq;
    }
    //插入P
    p->next = q->next;
    q->next->pred = p;
    p->pred = q;
    q->next = p;
  }
  return p;
}

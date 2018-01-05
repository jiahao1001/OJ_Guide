/*将两个有序顺序表合并成一个新的顺序表*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
  int data[50];
  int length;
}sqList;

sqList CreateSq(int n)
{
  sqList l;
  printf("请输入第%d个顺序表的个数:", n);
  scanf("%d",&l.length);
  printf("请依次输入第%d个顺序表的元素:", n);
  for(int i=0; i<l.length; i++)
  {
    scanf("%d", &l.data[i]);
  }
  return l;
}

sqList Merge(sqList *l1, sqList *l2)
{
  sqList l;
  l.length = l1->length + l2->length;
  int i=0, j=0, t=0;
  while (i<l1->length && j < l2->length) {
    if(l1->data[i] > l2->data[j])
      l.data[t++] = l2->data[j++];
    else
      l.data[t++] = l1->data[i++];
  }
  while (i<l1->length) {
    l.data[t++] = l1->data[i++];
  }
  while (j<l2->length) {
    l.data[t++] = l2->data[j++];
  }
  return l;
}

void Print(sqList *l)
{
  printf("现在顺序表中的元素依次为:");
  for(int i =0; i<l->length;i++)
      printf("%d ",l->data[i]);
  printf("\n");
}

int main()
{
  sqList l1 = CreateSq(1);
  sqList l2 = CreateSq(2);
  sqList l = Merge(&l1, &l2);
  Print(&l);
  return 0;
}

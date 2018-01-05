/*在一维数组A[m+n]中依次存放两个线性表a1~am和b1~bn
编写一个函数将数组中两个顺序表的位置互换，即A[b,a]*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
  int data[50];
  int m;
  int length;
}sqList;

sqList CreateSq()
{
  sqList l;
  printf("请输入顺序表的总个数:");
  scanf("%d",&l.length);
  printf("请依次输入顺序表的元素:");
  for(int i=0; i<l.length; i++)
  {
    scanf("%d", &l.data[i]);
  }
  printf("请输入第一个线性表的个数:");
  scanf("%d", &l.m);
  return l;
}

void Reverse(sqList *l, int start, int end)
{
  int tmp, t=(start+end+1) / 2;
  for(int i = start; i< t; i++)
  {
    tmp = l->data[i];
    l->data[i] = l->data[end+start-i];
    l->data[end+start-i] = tmp;
  }
}

void Reverse2List(sqList *l)
{
  int n = l->length - l->m;
  Reverse(l, 0, l->length-1);
  Reverse(l, 0, n-1);
  Reverse(l, n, l->length-1);
}

void Print(sqList *l)
{
  printf("现在线性表中的元素依次为:");
  for(int i=0; i<l->length; i++)
  {
    printf("%d ",l->data[i]);
  }
  printf("\n");
}

int main()
{
  sqList l = CreateSq();
  Reverse2List(&l);
  Print(&l);
  return 0;
}

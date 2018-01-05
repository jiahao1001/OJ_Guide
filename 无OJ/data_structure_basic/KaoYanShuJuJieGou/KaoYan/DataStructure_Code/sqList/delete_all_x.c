/*
删除顺序表中所有值为x的元素
要求时间复杂度O(N)，空间复杂度O(1)
*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
  int data[50];
  int length;
}sqList;

sqList CreateSq()
{
  sqList l;
  printf("请输入顺序表元素个数:");
  scanf("%d",&l.length);
  printf("请依次输入顺序表各个元素:");
  for(int i=0; i< l.length; i++)
  {
    scanf("%d", &l.data[i]);
  }
  return l;
}

void deleteAllX(sqList *l)
{
  int x;
  printf("请输入你要删除的元素:");
  scanf("%d", &x);
  //不去找等于x的，而去找不等于x的
  int j = 0;
  for(int i=0 ; i<l->length; i++)
  {
    if (l->data[i] != x) {
      l->data[j] = l->data[i];
      j++;
    }
  }
  l->length = j;
}

void Print(sqList *l)
{
  printf("现在顺序表中的元素依次为:\n");
  for(int i = 0; i < l->length; i++)
  {
    printf("%d ", l->data[i]);
  }
  printf("\n");
}

int main()
{
  sqList l = CreateSq();
  deleteAllX(&l);
  Print(&l);
  return 0;
}

/*从有序表中删除所有其值重复的元素*/

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

void Del_Repeat(sqList *l)
{
  int i, j=0;
  for(i=0;i<l->length-1; i++)
  {
    if(l->data[i+1] != l->data[i])
       {
         l->data[j] = l->data[i];
         j++;
       }
  }
  l->data[j] = l->data[l->length - 1];
  j++;
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
  Del_Repeat(&l);
  Print(&l);
  return 0;
}

/*设计高效的算法将顺序表中所有元素逆置，要求空间复杂度O(1)*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
  int data[50];
  int length;
}sqList;

sqList CreateSq()
{
  sqList l;
  printf("请输入顺序表的长度:");
  scanf("%d", &l.length);
  printf("请依次输入顺序表中的元素值:");
  for(int i = 0; i< l.length; i++)
      scanf("%d", &l.data[i]);
  return l;
}

void Reverse(sqList *l)
{
  //逆置顺序表
  int t = 0, tmp;
  while (t < l->length / 2) {
    /* code */
    tmp = l->data[t];
    l->data[t] = l->data[l->length-t-1];
    l->data[l->length-t-1] = tmp;
    t++;
  }
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
  sqList CreateSq();
  void Reverse(sqList *l);
  void Print(sqList *l);
  sqList l;
  l = CreateSq();
  Reverse(&l);
  Print(&l);
  return 0;
}

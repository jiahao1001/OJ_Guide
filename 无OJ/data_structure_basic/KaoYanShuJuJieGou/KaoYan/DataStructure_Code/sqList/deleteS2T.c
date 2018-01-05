/*在有序表中删除其值在给定s与t(s<t)之间的所有元素
如果s或t不合理或者顺序表为空则显示出错信息并退出运行*/

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

bool Del_s2t(sqList *l)
{
  int s, t;
  printf("请输入s和t的值:");
  scanf("%d%d",&s,&t);
  if(s>t || s == t)
  {
      printf("所输入的值不符合要求。\n");
      return false;
  }
  if(l->length == 0)
  {
      printf("线性表为空。\n");
      return false;
  }
  //有序顺序表
  int j = 0;
  for(int i=0; i<l->length; i++)
  {
    if(l->data[i] < s)
      j++;
    if(l->data[i] > t)
    {
      l->data[j] = l->data[i];
      j++;
    }
  }
  l->length = j;
  return true;
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
  if(Del_s2t(&l))
     Print(&l);
  return 0;
}

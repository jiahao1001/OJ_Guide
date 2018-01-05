/*删除线性表中最小的元素(假设唯一)，并由函数返回被删元素的值。
空出的位置由最后一个元素填补，若顺序表为空则显示出错信息并退出运行*/

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

void Del_Min(sqList *l)
{
  //删除其中最小值
  int pos=0, value;
  value = l->data[0];
  for(int i=0; i<l->length; i++)
  {
    if (l->data[i] < value) {
      /* code */
      value = l->data[i];
      pos = i;
    }
  }
  l->data[pos] = l->data[l->length - 1];
  l->length--;
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
    sqList l;
    l = CreateSq();
    Del_Min(&l);
    Print(&l);
    return 0;
}

/*线性表中元素递增有序且按顺序存储于计算机内。
要求设计一算法完成用最少时间在表中查找数值为x的元素，若找到将其与后继元素位置
相交换，若找不到将其插入表中并将表中元素仍然有序*/

#include <stdio.h>
#include <stdbool.h>

typedef struct{
  int data[50];
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
  return l;
}

void FindX(sqList *l)
{
  int x;
  printf("请输入你要查找的x:");
  scanf("%d",&x);
  //在有序表最短时间查找利用二分法
  int start=0, end=l->length-1,mid;
  while (start <= end) {
    mid = (start + end) / 2;
    if(l->data[mid] == x)
         break;
    else if(l->data[mid] < x)
        start = mid +1;
    else
        end = mid -1;
  }
  //找到后 若不是最后一位
  if(l->data[mid] == x && mid != l->length -1)
  {
    int t = l->data[mid];
    l->data[mid] = l->data[mid + 1];
    l->data[mid + 1] = t;
  }
  //未找到
  int i;
  if(start > end)
  {
    for(i = l->length-1; i > end; i--)
    {
      l->data[i+1] = l->data[i];
    }
    l->data[i+1] = x;
    //当插入时长度加1
    l->length ++;
  }
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
  sqList l = CreateSq();
  FindX(&l);
  Print(&l);
  return 0;
}

/*
已知一个整数序列A = (a0, a1, a2..., an-1)，其中0<=ai<n(0<=i<n)，
若存在ap1 = ap2=.....apm=x，且m>n/2(0<=pk<n,1<=k<=m)，则称x为A的主元素。
例如A=(0,5,5,3,5,7,5,5)，则5为主元素；又如A=(0,5,5,3,5,1,5,7)，则A中没有主元素
假设A中的n个元素保存在一个一维数组中，请设计一个尽可能高效的算法，找出A中的主元素
*/

/*可考虑采用先排序再比较的算法,这里采用一种比较高效的算法，
时间复杂度O(N),空间复杂度O（1）*/

#include <stdio.h>

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

int Majority(sqList *l)
{
  int i, c, count=1, n= l->length;
  c = l->data[0];
  for(i=1; i<n; i++)
      if(l->data[i]==c)
          count++;
      else
          if(count>0)
              count--;
          else{
            c = l->data[i];
            count = 1;
          }
  if(count>0)
      for(i=count=0; i<n;i++)
          if(l->data[i] == c)
              count++;
  if(count>n/2)  return c;
  else return -1;
}

int main()
{
  sqList l = CreateSq();
  int majorityNum = Majority(&l);
  printf("主元素为:%d\n",majorityNum);
  return 0;
}

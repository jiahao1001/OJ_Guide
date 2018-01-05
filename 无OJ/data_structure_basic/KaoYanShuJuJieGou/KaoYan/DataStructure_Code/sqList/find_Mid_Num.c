/*
一个长度为L(L>=1)的升序序列S，处在第[L/2]个位置的数称为中位数。
例如，若序列S1=(11， 13， 15， 17， 19)，则S1的中位数是15，
两个序列的中位数是含它们所有元素的升序序列的中位数，例如，
若S2=(2， 4， 6， 8 ，20),则S1和S2的中位数是11.现在有两个等长
升序序列A和B，试设计一个在时间和空间两方面都尽可能高效的算法，找出两个序列
的中位数。
*/
/*
可采用一般解法，但若要时间复杂度和空间都高效，这里采用另一种巧妙算法。
分别求升序序列A,B的中位数，设为a和b，则求两个序列的中位数如下：
（1）若a=b,则a或b即为所求的中位数，算法结束。
（2）若a<b，则舍弃序列A中较小的一半，同时舍弃序列B中较大的一半，要求
两次舍弃的长度相等。
（3）若a>b，则舍弃A中较大的一半，同时舍弃序列B中较小的一半，要求两次
舍弃的长度相等。
直到两个序列中均只含一个元素时为止，较小者即为所求的中位数。
*/


#include <stdio.h>

typedef struct{
  int data[50];
  int length;
}sqList;

sqList CreateSq(int n)
{
  sqList l;
  printf("请输入第%d个顺序表的总个数:", n);
  scanf("%d",&l.length);
  printf("请依次输入顺序表的元素:");
  for(int i=0; i<l.length; i++)
  {
    scanf("%d", &l.data[i]);
  }
  return l;
}

int M_search(sqList *l1, sqList *l2)
{
  //两个等长
  int s1=0, d1=l1->length-1, m1;
  int s2=0, d2=l2->length-1, m2;
  while(s1 != d1 || s2 != d2)
  {
    m1 = (s1+d1) /2;
    m2 = (s2+ d2) /2;
    if(l1->data[m1] == l2->data[m2])
         return l1->data[m1];
    if(l1->data[m1] < l2->data[m2])
    {
      if((s1+d1)%2 == 0){   //若元素个数为奇数
        s1 = m1;
        d2 = m2;
      }
      else{
        s1 = m1 + 1;
        d2 = m2;
      }
    }
    else
    {
      if((s2+d2) %2 ==0){
        d1 = m1;
        s2 = m2;
      }
      else{
        d1 = m1;
        s2 = m2 + 1;
      }
    }
  }
  return l1->data[s1] < l2->data[s2] ? l1->data[s1]:l2->data[s2];
}

int main()
{
  sqList l1 = CreateSq(1);
  sqList l2 = CreateSq(2);
  int mid = M_search(&l1, &l2);
  printf("中位数为:%d\n",mid);
  return 0;
}

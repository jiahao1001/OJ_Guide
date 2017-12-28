#include <stdio.h>

int findKth(int *s, int n, int K)
{
    int i=-1,j,tmp,r=s[n-1],p;
    /*
    r为选取的基准元素。选取最后一个元素作为基准元素，不参加比较。
    比其小的，放在数组的前面。
    最后将基准元素放到所有比它小的元素的后一个位置上。

    这种实现方式比较简单又易于理解。另一种实现方式：
    选取第一个为基准元素，遍历数组：遇到比基准元素小的，与当前搜索区的第一个元素交换，
    将第一个元素加入到“比基准小”的集合中；遇到比基准元素大的，与当前搜索区的最后一个元素交换，
    将最后一个元素加入到“比基准大”的集合中。最后搜索区只剩下一个基准元素。
    */

    for(j=0;j<n-1;j++)  
    {
        if(s[j]<r)
        {
            i++;  //i记录比r小的所有元素的最后下标
            tmp=s[i];
            s[i]=s[j];
            s[j]=tmp;
        }
    }
    i++;
    tmp=s[i];s[i]=s[j];s[j]=tmp;
    p=i;  //p此时为基准元素的下标

    if(p==K-1)return r;
    else if(p>=K)return findKth(s,p,K);
    else return findKth(s+p+1,n-p-1,K-p-1);

}

int main()
{
    int s[6]={2,3,5,6,4,1};
    findKth(s,6,3);
    return 0;
}
#include <cstdio>
long long **sum,**res;
int n;
int main()
{
    scanf("%d",&n);
    int *data=new int[n];
    int i,j;
    for (i=0;i<n;++i) scanf("%d",&data[i]);
    sum=new long long*[n];
    res=new long long*[n];
    res[0]=new long long[1];
    res[0][0]=0;
    for (i=1;i<n;++i)
    {
        sum[i]=new long long[i];
        res[i]=new long long[i+1];
        sum[i][i-1]=data[i]+data[i-1];
        res[i][i]=0;
        res[i][i-1]=data[i]+data[i-1];
        for (j=i-2;j>=0;--j) sum[i][j]=data[j]+sum[i][j+1];
    }
    for (i=2;i<n;++i)
    {

    }
}

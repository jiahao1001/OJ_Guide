#include <cstdio>
int main()
{
    int n,k,i=1,len=0;
    int array[40]={0};
    long long matrix[40]={0};
    long long ii=1;
    scanf("%d %d",&n,&k);
    while (n>0)
    {
        matrix[len]=ii;
        ii*=2;
        array[len++]=n%2;
        n/=2;
    }
    matrix[len]=ii;
    int count=0,res=0;
    for (i=0;i<len;++i) if (array[i]==1) ++count;
    i=0;
    while (count>k)
    {
        while (array[i]==0) ++i;
        res+=matrix[i];
        while (array[i]==1)
        {
            array[i]=0;
            ++i;
            --count;
        }
        array[i]=1;
        ++count;
    }
    printf("%d",res);
}

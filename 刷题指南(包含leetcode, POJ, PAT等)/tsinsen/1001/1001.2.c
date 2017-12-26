#include<stdio.h>

//将数字转化为二进制方法
int main()
{
    int a,j,i,m,n;
    int s[6];
    a=0;
    for(;a<64;a++)
    {
        i=a%2,j=a/2;
        for(m=0;m<6;m++)
        {
            s[m]=i;
            i=j%2,j=j/2;
        }
        for(n=5;n>=0;n--)
        {
            printf("%d",s[n]);
        }
        printf("\n");
    }
    return 0;    
}
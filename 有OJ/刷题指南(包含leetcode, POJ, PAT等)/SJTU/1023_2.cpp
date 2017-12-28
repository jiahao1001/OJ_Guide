#include <stdio.h>
int data[600][600];
int a,b;
int main()
{
    int n,p,i,j;
    scanf("%d",&n);
    for (p=0;p<n;++p)
    {
        scanf("%d %d",&a,&b);
        for (i=0;i<a;++i) for (j=0;j<a;++j) scanf("%d",&data[i][j]);
        if (b==0)
        {
            for (i=0;i<a;++i)
            {
                for (j=a-1;j>=0;--j) printf("%d ",data[i][j]);
                printf("\n");
            }
        }else if (b==1)
        {
            for (i=a-1;i>=0;--i)
            {
                for (j=0;j<a;++j) printf("%d ",data[i][j]);
                printf("\n");
            }
        }else
        {
            for (i=0;i<a;++i)
            {
                for (j=0;j<a;++j) printf("%d ",data[j][i]);
                printf("\n");
            }
        }
    }
}

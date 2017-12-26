#include<stdio.h>
int main()
{
	int c[14],p[14];
	int t,n,i,j,k,s,h,r;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n-1;j++)
			p[j]=j+1;
        s=1;
        h=1;
        r=n;
        for(k=1;k<=n;k++)
        {
            for(j=1;j<=k;j++)
            {
                p[r]=h;
                h=p[h];
                r=p[r];
            }
            c[h]=k;
            h=p[h];
        }
        for(j=1;j<=n;j++)
            printf("%d ",c[j]);
        printf("\n");
    }
	return 0;
}

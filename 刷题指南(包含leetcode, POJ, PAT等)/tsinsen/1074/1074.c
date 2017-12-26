#include <stdio.h>
#include <string.h>

int a[110][110];
int x[110];

int main()
{
    memset(a,0,sizeof(a));
    memset(x,0,sizeof(x));

    int n,i,j;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    for(i=0;i<n;i++)scanf("%d",&x[i]);

    for(i=0;i<n;i++)
    {
        int sum=0;
        for(j=0;j<n;j++)
            sum+=a[i][j]*x[j];
        printf("%d\n",sum);
    }

    return 0;

}

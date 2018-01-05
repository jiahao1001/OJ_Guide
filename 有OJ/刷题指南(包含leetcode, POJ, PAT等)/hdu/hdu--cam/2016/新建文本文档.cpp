#include <stdio.h>
int main (void)
{
	freopen("2016.in", "r", stdin);
	freopen("2016.out", "w", stdout);
    int n,i,a[100],min,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(!n)
            break;
        scanf("%d",&a[0]);
        min=0,j=a[0];
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]<j)   //用j记录最小值勇于比较，并用min记录最小值的位置
            {
                j=a[i];
                min=i;
            }
        }
        j=a[0],a[0]=a[min],a[min]=j,j=0;
        for(i=0;i<n;i++)
        {
            if(j)
                printf(" ");
            printf("%d",a[i]);
            j=1;
        }
        printf("\n");
    }
    return 0;
}

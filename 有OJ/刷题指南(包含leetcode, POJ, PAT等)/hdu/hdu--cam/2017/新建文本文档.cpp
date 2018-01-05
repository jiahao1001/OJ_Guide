#include <stdio.h>
#include <string.h>
int main (void)
{	freopen("2017.in", "r", stdin);
	freopen("2017.out", "w", stdout);
    int n,i,j,k,s;
    char a[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        s=0;
        scanf("%s",a);
        j=strlen(a);
        for(k=0;k<j;k++)
            if(a[k]>='0'&&a[k]<='9')   //判断是不是数字
                s++;
            printf("%d\n",s);
    }
    return 0;
}

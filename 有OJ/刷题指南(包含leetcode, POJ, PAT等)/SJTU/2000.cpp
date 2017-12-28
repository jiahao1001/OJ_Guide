#include <stdio.h>
int main()
{
    int n,t,res=0,i;
    scanf("%d",&n);
    for (i=0;i<n;++i)
    {
        scanf("%d",&t);
        res+=t;
    }
    printf("%d",res);
}

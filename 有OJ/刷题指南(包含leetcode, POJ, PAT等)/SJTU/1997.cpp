#include <stdio.h>
int main()
{
    int n,w,m,i,min=20000,t,res;
    scanf("%d %d",&n,&w);
    for (i=0;i<n;++i)
    {
        scanf("%d",&m);
        if (m<w)
        {
            t=w-m;
            if (t<min)
            {
                min=t;
                res=m;
            }
        }else
        {
            t=m-w;
            if (t<=min)
            {
                min=t;
                res=m;
            }
        }
    }
    printf("%d",res);
}

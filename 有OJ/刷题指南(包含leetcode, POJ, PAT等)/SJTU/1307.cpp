#include <cstdio>
#include <cmath>
bool pf(int n)
{
    double t=n;
    int p=sqrt(t);
    return (p*p==n);
}
int main()
{
    int n,i,t=1;
    int pals[50]={0};
    scanf("%d",&n);
    while (true)
    {
        for (i=0;i<n;++i) if (pals[i]==0 || pf(pals[i]+t))
        {
            pals[i]=t++;
            break;
        }
        if (i==n) break;
    }
    printf("%d",--t);
}

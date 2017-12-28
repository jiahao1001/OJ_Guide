#include<stdio.h>
#include<math.h>
double r[1001];
double dist[1001];
int n;
int dispensible[1001];
int cnt;
double width(double r1, double r2)
{
    return 2*sqrt(r1*r2);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf",r+i);
    dist[1]=r[1];
    int rightmost=1;
    double most=2*r[1];
    for(int i=2;i<=n;i++)
    {
        dist[i]=0;
        int li=i-1;
        for(int j=i-1;j>=1;j--)
            if(!dispensible[j] && dist[j]+width(r[j],r[i])>dist[i])
                dist[i]=dist[j]+width(r[j],r[i]),li=j;
        if(dist[i]<r[i]) dist[i]=r[i],li=0;
        for(int j=i-1;j>li;j--)
            if(!dispensible[j]) dispensible[j]=1,cnt++;
        
        if(dist[i]+r[i]>most) most=dist[i]+r[i],rightmost=i;
    }
    for(int i=rightmost+1;i<=n;i++)
        if(!dispensible[i]) dispensible[i]=1,cnt++;
    
    
    printf("%d\n",cnt);
    for(int i=1;i<=n;i++)
        if(dispensible[i]) printf("%d\n",i);
    
    return 0;
    
    
}

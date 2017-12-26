#include<stdio.h>
int n,m;
int money[100000];
bool check(int lim)
{
    int sum=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(money[i]>lim) return false;
        if(sum+money[i]<=lim) sum+=money[i];
        else{
            cnt++;
            sum=money[i];
        }
    }
    cnt++;
    return cnt<=m;
}
int main()
{
    scanf("%d%d",&n,&m);
    int sum=0;
    for(int i=0;i<n;i++)
        scanf("%d",money+i),sum+=money[i];
    int l=0,r=sum;
    int mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    return 0;
}

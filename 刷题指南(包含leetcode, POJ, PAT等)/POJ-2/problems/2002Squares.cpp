#include<iostream>
#include<string.h>
#include<set>
using namespace std;
int x[1000],y[1000];
set<int> ps;
int beyond(int x)
{
    return x<0 || x>=40000;
}
int in(int x1,int y1,int x2,int y2)
{
    if(beyond(x1)||beyond(y1)||beyond(x2)||beyond(y2)) return 0;
    if (ps.find(y1*40000+x1)!=ps.end() && ps.find(y2*40000+x2)!=ps.end()) return 1;
    return 0;
}
int check(int i,int j)
{
    int dx=x[i]-x[j],dy=y[i]-y[j];
    return in(x[i]+dy,y[i]-dx,x[j]+dy,y[j]-dx) + in(x[i]-dy,y[i]+dx,x[j]-dy,y[j]+dx);
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        ps.clear();
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",x+i,y+i);
            x[i]+=20000,y[i]+=20000;
            ps.insert(y[i]*40000+x[i]);
        }
        int total=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                total+=check(i,j);
        //cout<<total<<endl;
        printf("%d\n",total/4);
    }
    return 0;
}

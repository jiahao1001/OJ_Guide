#include <iostream>
using namespace std;
int n,solution=0;
int res[15];
void search(int level)
{
    int i;
    if (level==n+1)
    {
        ++solution;
        if (solution<=3)
        {
            for (i=1;i<=n;++i) cout<<res[i]<<' ';
            cout<<'\n';
        }
        return;
    }
    bool can[14];
    for (i=1;i<=n;++i) can[i]=true;
    int t;
    for (i=1;i<level;++i)
    {
        can[res[i]]=false;
        t=res[i]+level-i;
        if (1<=t && t<=n) can[t]=false;
        t=res[i]-level+i;
        if (1<=t && t<=n) can[t]=false;
    }
    for (i=1;i<=n;++i) if (can[i])
    {
        res[level]=i;
        search(level+1);
    }
}
int main()
{
    cin>>n;
    search(1);
    cout<<solution<<'\n';
}

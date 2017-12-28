#include <iostream>
using namespace std;
int main()
{
    bool f[10001];
    int l,m,i,j,s,e,res=0;
    cin>>l>>m;
    for (i=0;i<=l;++i) f[i]=true;
    for (i=0;i<m;++i)
    {
        cin>>s>>e;
        if (s>e)
        {
            s+=e;
            e=s-e;
            s-=e;
        }
        for (j=s;j<=e;++j) f[j]=false;
    }
    for (i=0;i<=l;++i) if (f[i]) ++res;
    cout<<res;
}

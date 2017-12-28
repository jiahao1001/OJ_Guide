#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v;
    int a,b,x,m,n,i;
    cin>>a>>b>>x>>m>>n;
    while ((a!=-1)||(b!=-1)||(x!=-1)||(m!=-1)||(n!=-1))
    {
        for (i=1;i<n;++i) x=(a*x+b)%m;
        v.push_back(x);
        cin>>a>>b>>x>>m>>n;
    }
    x=v.size();
    for (i=0;i<x;++i) cout<<v[i]<<endl;
}

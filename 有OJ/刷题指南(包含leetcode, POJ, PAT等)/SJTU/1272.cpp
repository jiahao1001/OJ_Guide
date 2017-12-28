#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int div(int a,int b)
{
    if (a>b)
    {
        a+=b;
        b=a-b;
        a-=b;
    }
    return b/a;
}
int main()
{
    bool res[101]={0};
    queue<int> q;
    vector<int> v;
    int n,i,t,j,p;
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>t;
        res[t]=true;
        for (j=0;j<v.size();++j)
        {
            p=div(t,v[j]);
            if (!res[p])
            {
                q.push(p);
                res[p]=true;
            }
        }
        v.push_back(t);
    }
    while (!q.empty())
    {
        t=q.front();
        for (j=0;j<v.size();++j)
        {
            p=div(t,v[j]);
            if (!res[p])
            {
                q.push(p);
                res[p]=true;
            }
        }
        v.push_back(t);
        q.pop();
    }
    int count=0;
    for (i=1;i<100;++i) if (res[i]) ++count;
    cout<<count;
}

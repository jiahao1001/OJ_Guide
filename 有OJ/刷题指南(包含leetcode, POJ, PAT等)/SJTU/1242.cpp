#include <iostream>
using namespace std;
int main()
{
    bool* q=new bool[10000];
    int i,j;
    q[0]=false;
    for (i=1;i<10000;++i)
    {
        q[i]=true;
    }
    int t=97;
    for (i=2;i<=t;++i)
    {
        if (q[i-1])
        {
            for (j=2*i;j<=10000;j+=i) q[j-1]=false;
        }
    }
    int a,b,c=0;
    cin>>a>>b;
    for (i=a;i<=b;++i) if (q[i-1]) ++c;
    cout<<c;
}

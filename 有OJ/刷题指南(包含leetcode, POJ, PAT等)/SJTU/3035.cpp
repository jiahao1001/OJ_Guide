#include <iostream>
using namespace std;
int p(int a)
{
    if (a>=999) return 0;
    if (a>=888) return 1;
    if (a>=777) return 2;
    if (a>=666) return 3;
    if (a>=555) return 4;
    if (a>=444) return 5;
    if (a>=333) return 6;
    if (a>=222) return 7;
    if (a>=111) return 8;
    return 9;
}
int main()
{
    int n,a,b,i,c[10]={0};
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>a>>b;
        a=a*7+b*3;
        ++c[p(a)];
    }
    b=0;
    for (i=1;i<10;++i) if (c[i]>c[b]) b=i;
    cout<<b+1;
}

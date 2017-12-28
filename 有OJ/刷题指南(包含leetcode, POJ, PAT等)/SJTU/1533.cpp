#include <iostream>
using namespace std;
int min(int a,int b)
{
    return (a>b)?b:a;
}
int main()
{
    int n,x,y,round;
    long long res=-1;
    cin>>n>>x>>y;
    round=min(min(x,n+1-x),min(y,n+1-y))-1;
    res+=(round*(4*n-2-2*round));
    if (x==round+1) res+=(y-round);
    else if (y==n-round) res+=(y-round+x-round-1);
    else if (x==n-round) res+=(3*n-5*round-y-1);
    else res+=(4*n-7*round-x-2);
    cout<<res;
}

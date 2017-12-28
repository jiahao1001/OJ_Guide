#include <iostream>
using namespace std;
int no(int n,int x,int y)
{
    if (x==1) return y;
    else if (y==n) return (n+x-1);
    else if (x==n) return (3*n-y-1);
    else if (y==1) return (4*n-x-2);
    else return (4*n-4+no(n-2,x-1,y-1));
}
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    cout<<(no(n,x,y)-1);
}

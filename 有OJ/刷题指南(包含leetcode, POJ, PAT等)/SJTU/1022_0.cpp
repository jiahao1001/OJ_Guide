#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int fib[2040],n,i;
    long long x;
    cin>>x;
    n=x%2040;
    fib[0]=1;
    fib[1]=1;
    for (i=2;i<2040;++i) fib[i]=(fib[i-2]+fib[i-1])%2010;
    cout<<fib[n-1];
}

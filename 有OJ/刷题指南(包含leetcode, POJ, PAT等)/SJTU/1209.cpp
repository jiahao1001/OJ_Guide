#include <iostream>
using namespace std;
int two(int n)
{
    int count=0;
    while (n>0)
    {
        if (n%2==1) ++count;
        n/=2;
    }
    return count;
}
int main()
{
    int n,i,t;long long c=0;
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>t;
        c+=two(t);
    }
    cout<<c;
}

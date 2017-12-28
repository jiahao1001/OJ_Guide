#include <iostream>
using namespace std;
int main()
{
    int m,i,*t,s=0;
    cin>>m;
    t=new int[m-1];
    for (i=m-2;i>=0;--i) cin>>t[i];
    for (i=2;i<=m;++i) s=(s+t[i-2])%i;
    cout<<s+1;
    delete [] t;
}

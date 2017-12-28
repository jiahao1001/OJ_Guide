#include <iostream>
using namespace std;
int mmm(int a,int b)
{
    return (a>b)?a:b;
}
int main()
{
    int m,i,n[100],max=0;
    cin>>m;
    for (i=0;i<m;++i)
    {
        cin>>n[i];
        if (n[i]>max) max=n[i];
    }
    unsigned long long *res=new unsigned long long[mmm(max+1,5)];
    res[0]=1;res[1]=0;res[2]=1;res[3]=1;res[4]=1;
    for (i=5;i<=max;++i) res[i]=res[i-2]+res[i-3]+res[i-5]-1;
    for (i=0;i<m;++i) cout<<res[n[i]]<<'\n';
    delete [] res;
}

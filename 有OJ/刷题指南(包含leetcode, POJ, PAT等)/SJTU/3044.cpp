#include <iostream>
using namespace std;
int main()
{
    int n,i,j;int* x;
    cin>>n;
    if (n>2) x=new int[n];else x=new int[2];
    x[0]=1;x[1]=2;
    for (i=2;i<n;++i)
    {
        x[i]=1;
        for (j=i%2;j<i;j+=2) x[i]+=x[j];
    }
    cout<<x[n-1];
    delete [] x;
}

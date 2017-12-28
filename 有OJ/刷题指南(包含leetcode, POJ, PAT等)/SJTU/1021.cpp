#include <iostream>
#include <iomanip>
using namespace std;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int main()
{
    int n,i,j=0,t=1,d=0;
    cin>>n;int m=n*n;
    if (n==1)
    {
        cout<<setw(6)<<1;
        return 0;
    }
    int** mt=new int*[n];
    for (i=0;i<n;++i)
    {
        mt[i]=new int[n];
        for (j=0;j<n;++j) mt[i][j]=0;
    }
    j=0;
    for (i=0;i<n;++i) mt[0][i]=i+1;
    for (i=1;i<n;++i) mt[i][n-1]=i+n;
    for (i=1;i<n;++i) mt[n-1][n-i-1]=2*n+i-1;
    for (i=1;i<n-1;++i) mt[n-1-i][0]=3*n+i-2;
    i=1;t=4*n-3;j=1;d=0;
    while (t<=m)
    {
        mt[i][j]=t;
        ++t;
        if (mt[i+dx[d]][j+dy[d]]!=0) d=(d+1)%4;
        i+=dx[d];
        j+=dy[d];
    }
    for (i=0;i<n;++i)
    {
        for (j=0;j<n;++j) cout<<setw(6)<<mt[i][j]<<' ';
        cout<<endl;
        delete [] mt[i];
    }
    delete [] mt;
}

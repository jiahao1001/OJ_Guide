#include <iostream>
using namespace std;
int Max(int a,int b)
{
    return ((a>b)?a:b);
}
int main()
{
    int n,m,i,j;
    char x[1001],y[1001];
    static int res[1001][1001]={0};
    cin>>n>>m>>x>>y;
    for (i=1;i<=n;++i) for (j=1;j<=m;++j)
    {
        if (x[i-1]==y[j-1]) res[i][j]=res[i-1][j-1]+1;
        else res[i][j]=Max(res[i-1][j],res[i][j-1]);
    }
    cout<<res[n][m];
}

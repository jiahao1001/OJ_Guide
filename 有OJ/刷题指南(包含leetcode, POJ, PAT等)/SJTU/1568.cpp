#include <iostream>
using namespace std;
int main()
{
    int n,m,p,i,j,k;cin>>n>>m>>p;
    int **a=new int*[n],**b=new int*[m],**c=new int*[n];
    for (i=0;i<n;++i)
    {
        a[i]=new int[m];
        c[i]=new int[p];
        for (j=0;j<m;++j) cin>>a[i][j];
    }
    for (i=0;i<m;++i)
    {
        b[i]=new int[p];
        for (j=0;j<p;++j) cin>>b[i][j];
    }
    for (i=0;i<n;++i) for (j=0;j<p;++j)
    {
        c[i][j]=0;
        for (k=0;k<m;++k) c[i][j]+=a[i][k]*b[k][j];
    }
    for (i=0;i<n;++i)
    {
        for (j=0;j<p;++j) cout<<c[i][j]<<' ';
        cout<<'\n';
    }
    for (i=0;i<n;++i) delete [] a[i];
    for (i=0;i<m;++i) delete [] b[i];
    for (i=0;i<n;++i) delete [] c[i];
    delete [] a;
    delete [] b;
    delete [] c;

}

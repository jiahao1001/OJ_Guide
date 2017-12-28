#include <cstdio>
int n;
bool mat[410][410]={0};
template <class T>
class Sum
{
private:
    T** data;
    int size;
public:
    Sum(int n=410):size(n)
    {
        data=new T*[n];
        for (int i=0;i<n;++i) data[i]=new T[i+1];
    }
    ~Sum()
    {
        for (int i=0;i<size;++i) delete [] data[i];
        delete [] data;
    }
    T*& operator[](int pos){return data[pos];}
};
long long ODD=0,NODD=0;
int main()
{
    freopen("1228.in","r",stdin);
    scanf("%d",&n);
    int i,j,k,x,y,z;
    Sum<bool> **summary=new Sum<bool>*[n];
    for (int i=0;i<n;++i) summary[i]=new Sum<bool>[i+1];
    for (i=0;i<n;++i) for (j=0;j<n;++j)
    {
        scanf("%d",&k);
        mat[i][j]=k%2;
        summary[i][i][j][j]=mat[i][j];
        if (mat[i][j]) ++ODD;else ++NODD;
    }
    //printf("%lld %lld\n",ODD,NODD);
    for (i=0;i<n-1;++i) for (j=i+1;j<n;++j) for (k=0;k<n;++k)
    {
        summary[j][i][k][k]=(mat[j][k])?(!summary[j-1][i][k][k]):summary[j-1][i][k][k];
        if (summary[j][i][k][k]) ++ODD;else ++NODD;
    }
    //printf("%lld %lld\n",ODD,NODD);
    for (i=0;i<n-1;++i) for (j=i+1;j<n;++j) for (k=0;k<n;++k)
    {
        summary[k][k][j][i]=(mat[k][j])?(!summary[k][k][j-1][i]):summary[k][k][j-1][i];
        if (summary[k][k][j][i]) ++ODD;else ++NODD;
    }
    //printf("%lld %lld\n",ODD,NODD);
    for (i=2;i<=n;++i) for (j=2;j<=n;++j) for (k=0;k<=n-i;++k) for (x=0;x<=n-j;++x)
    {
        summary[k+i-1][k][x+j-1][x]=(summary[k+i-1][k][x+j-1][x+j-1])?(!summary[k+i-1][k][x+j-2][x]):summary[k+i-1][k][x+j-2][x];
        if (summary[k+i-1][k][x+j-1][x]) ++ODD;else ++NODD;
    }
    printf("%lld %lld\n",ODD,NODD);
    for (int i=0;i<n;++i) delete [] summary[i];
    delete [] summary;
}

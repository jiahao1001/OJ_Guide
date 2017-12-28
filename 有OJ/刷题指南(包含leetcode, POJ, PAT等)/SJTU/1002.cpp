#include <iostream>
using namespace std;
int main()
{
    unsigned long l,w,a,b,max=0;
    long i,j,x,y;
    cin>>l>>w;
    int** field=new int*[l];
    for (i=0;i<l;++i)
    {
        field[i]=new int[w];
        for (j=0;j<w;++j) cin>>field[i][j];
    }
    cin>>a>>b;
    x=l-a;y=w-b;
    unsigned long** f2=new unsigned long*[l];
    for (i=0;i<l;++i) f2[i]=new unsigned long[y+1];
    unsigned long** f3=new unsigned long*[x+1];
    for (i=0;i<x+1;++i) f3[i]=new unsigned long[y+1];
    for (i=0;i<l;++i)
    {
        f2[i][y]=0;
        for (j=y;j<w;++j) f2[i][y]+=field[i][j];
        for (j=y-1;j>=0;--j) f2[i][j]=field[i][j]+f2[i][j+1]-field[i][j+b];
    }
    for (j=0;j<y+1;++j)
    {
        f3[x][j]=0;
        for (i=x;i<l;++i) f3[x][j]+=f2[i][j];
        if (f3[x][j]>max) max=f3[x][j];
        for (i=x-1;i>=0;--i)
        {
            f3[i][j]=f2[i][j]+f3[i+1][j]-f2[i+a][j];
            if (f3[i][j]>max) max=f3[i][j];
        }
    }
    cout<<max;
    for (i=0;i<l;++i) delete [] field[i];
    delete [] field;
    for (i=0;i<l;++i) delete [] f2[i];
    delete [] f2;
    for (i=0;i<x+1;++i) delete [] f3[i];
    delete [] f3;
}

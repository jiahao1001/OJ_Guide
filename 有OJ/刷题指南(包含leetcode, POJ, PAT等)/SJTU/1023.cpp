#include <iostream>
using namespace std;
class matrix
{
private:
    int length,direction;
    int **data;
public:
    matrix(){}
    matrix(int n,int m):length(n),direction(m)
    {
        data=new int*[n];
        for (int i=0;i<n;++i) data[i]=new int[n];
    }
    friend istream& operator>>(istream& in,matrix& m);
    friend ostream& operator<<(ostream& out,const matrix& m);
    ~matrix()
    {
        for (int i=0;i<length;++i) delete [] data[i];
        delete [] data;
    }
};
int main()
{
    int n,i,a,b;
    cin>>n;
    matrix** x=new matrix*[n];
    for (i=0;i<n;++i)
    {
        cin>>a,b;
        x[i]=new matrix(a,b);
        cin>>(*(x[i]));
    }
    for (i=0;i<n;++i) cout<<(*(x[i]));
    for (i=0;i<n;++i) delete x[i];
    delete [] x;
}
istream& operator>>(istream& in,matrix& m)
{
    for (int i=0;i<m.length;++i) for (int j=0;j<m.length;++j) in>>m.data[i][j];
    for (int i=0;i<m.length;++i)
    {
        for (int j=0;j<m.length;++j) cout<<m.data[i][j]<<' ';
        cout<<endl;
    }
    return in;
}
ostream& operator<<(ostream& out,const matrix& m)
{
    int i,j;
    switch (m.direction)
    {
        case 0:for (i=0;i<m.length;++i)
               {
                   for (j=m.length-1;j>=0;--j) out<<m.data[i][j]<<' ';
                   out<<endl;
               }
               break;
        case 1:for (i=m.length-1;i>=0;--i)
               {
                   for (j=0;j<m.length;++j) out<<m.data[i][j]<<' ';
                   out<<endl;
               }
               break;
        case 2:for (i=0;i<m.length;++i)
               {
                   for (j=0;j<m.length;++j) out<<m.data[j][i]<<' ';
                   out<<endl;
               }
               break;
    }
    return out;
}

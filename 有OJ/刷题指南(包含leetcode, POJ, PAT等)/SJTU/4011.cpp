#include <cstdio>
class Bint
{
private:
    int data[256];
    int length;
public:
    Bint()
    {
        length=1;
        for (int i=0;i<256;++i) data[i]=0;
    }
    Bint(int v)
    {
        length=0;
        while (v>0)
        {
            data[length++]=v%10;
            v/=10;
        }
    }
    Bint(const Bint& other)
    {
        length=other.length;
        for (int i=0;i<length;++i) data[i]=other.data[i];
    }
    Bint& operator=(const Bint& other)
    {
        if (this==&other) return *this;
        length=other.length;
        for (int i=0;i<length;++i) data[i]=other.data[i];
        return *this;
    }
    friend Bint operator+(const Bint& a,const Bint& b);
    Bint& operator+=(const Bint& other)
    {
        int i;
        for (i=length;i<=other.length;++i) data[i]=0;
        if (length<other.length) length=other.length;
        data[length]=0;
        for (i=0;i<length;++i) data[i]+=other.data[i];
        if (data[length]!=0) ++length;
        return *this;
    }
    void print()
    {
        for (int i=length-1;i>=0;--i) printf("%d",data[i]);
    }
};
Bint operator+(const Bint& a,const Bint& b)
{
    Bint tmp;
    tmp.length=(a.length>b.length)?a.length:b.length;
    tmp.data[tmp.length]=0;
    int i;
    for (i=0;i<tmp.length;++i) tmp.data[i]=a.data[i]+b.data[i];
    for (i=0;i<tmp.length;++i) if (tmp.data[i]>=10)
    {
        tmp.data[i+1]+=tmp.data[i]/10;
        tmp.data[i]%=10;
    }
    if (tmp.data[tmp.length]!=0) ++tmp.length;
    return tmp;
}
Bint mat[2][51];
int main()
{
    int h,k,i,j,flag=0,l;
    scanf("%d %d",&k,&h);
    mat[0][k]=1;
    for (i=1;i<h;++i)
    {
        mat[1-flag][1]=mat[flag][k];
        for (j=2;j<=k;++j) mat[1-flag][j]=mat[1-flag][j-1]+mat[flag][k-j+1];
        flag=1-flag;
/*
        for (l=1;l<=k;++l)
        {
            mat[flag][l].print();
            printf(" ");
        }
        printf("%d\n",i);
*/
    }
    Bint res;
    //for (i=1;i<=k;++i) mat[flag][i].print();
    for (i=1;i<=k;++i) res=res+mat[flag][i];
    res.print();
}

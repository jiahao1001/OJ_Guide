#include <iostream>
using namespace std;
int b[100010];
int n,k;
class Bit
{
public:
    int* a;
    int size;
    Bit(int n)
    {
        size=n;
        a=new int [n+1];
        for(int i=0;i<=n;i++)
            a[i]=0;
    }
    ~Bit()
    {
        delete [] a;
    }
    long long sum(int pos)
    {
        long long  res=0;
        while(pos>0)
        {
            res+=a[pos];
            res%=1000000007;
            pos-=pos&(-pos);
        }
        return res;
    }
    void add(int pos, int num)
    {
        num%=1000000007;
        while(pos<=size)
        {
            a[pos]+=num;
            a[pos]%=1000000007;
            pos+=pos&(-pos);
        }
    }

} ;
template <class T>
void exchange(T &a,T&b)
{
    T c;
    c=a;
    a=b;
    b=c;
}
template <class T>
void qsort(T*a ,int l,int r)
{
    if(l>=r)
        return;
    exchange(a[(3*l+5*r)/8],a[l]);
    T key=a[l];
    int i=l;
    int j=r;
    while(i<j)
    {
        while((a[j]>=key)&&(i<j))
            j--;
        a[i]=a[j];
        while((a[i]<=key)&&(i<j))
            i++;
        a[j]=a[i];
    }
    a[i]=key;
    qsort(a,l,i-1);
    qsort(a,i+1,r);
}
struct imt
{
    int elem;
    int pos;
}a[100010];
bool operator<=(imt a,imt b)
{
    return a.elem<=b.elem;
}
bool operator>=(imt a,imt b)
{
    return a.elem>=b.elem;
}
void lisanhua(imt *a,int len)
{
    qsort(a,1,len);
    //cout<<"1";
    int j=1;
    a[len+1].elem=0x7ffffff;
    for(int i=1;i<=len;i++)
    {
        b[a[i].pos]=j;
        if(a[i].elem!=a[i+1].elem)
            j++;
    }
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].elem;
        a[i].pos=i;
    }
    //cout<<"s";
    lisanhua(a,n);
    //for(int i=1;i<=n;i++)
      //  cout<<b[i];
    Bit** c;
    c=new Bit* [k+1];
    for(int i=0;i<=k;i++)
        c[i]=new Bit(n);

    long long res=0;
    for(int i=n;i>=1;i--)
    {
        c[1]->add(b[i],1);
        for(int j=2;j<=k;j++)
        {
            c[j]->add(b[i],c[j-1]->sum(b[i]-1));
        }
    }
    res=c[k]->sum(n);
    cout<<res%1000000007;

}

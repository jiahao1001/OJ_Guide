#include <iostream>
#include <algorithm>
using namespace std;
class Set
{
private:
    int data[200];
    int size,schedule;
    //void qsort(int l=0,int r=size-1);
    int b_search(int value);
    int bb_search(int value);
    void insert(int value);
    void remove(int value);
public:
    Set(int s):size(0),schedule(s){}
    Set(const Set& other):size(other.size)
    {
        for (int i=0;i<size;++i) data[i]=other.data[i];
    }
    Set& operator=(const Set& other)
    {
        if (this==&other) return (*this);
        size=other.size;
        for (int i=0;i<size;++i) data[i]=other.data[i];
        return (*this);
    }
    Set& operator+=(const Set& other);
    Set& operator-=(const Set& other);
    Set& operator*=(const Set& other);
    friend istream& operator>>(istream& in,Set& s);
    friend ostream& operator<<(ostream& out,const Set& s);
};
/*void Set::qsort(int l=0,int r=size-1)
{
    if (l>=r) return;
    int i=l,j=r,v=data[i];
    while (i<j)
    {
        while ((i<j)&&(data[j]>=v)) --j;
        data[i]=data[j];
        while ((i<j)&&(data[i]<=v)) ++i;
        data[j]=data[i];
    }
    data[i]=v;
    qsort(l,i-1);
    qsort(i+1,r);
}*/
int Set::b_search(int value)
{
    int l=0,r=size-1,mid;
    while (l<=r)
    {
        mid=(l+r)/2;
        if (data[mid]==value) return mid;
        if (data[mid]<value) l=mid+1;else r=mid-1;
    }
    return -1;
}
int Set::bb_search(int value)
{
    int l=0;
    while (l<size && data[l]<value) ++l;
    return l;
}
void Set::insert(int value)
{
    if (b_search(value)==-1)
    {
        int pos=bb_search(value),i;
        for (i=size;i>pos;--i) data[i]=data[i-1];
        data[pos]=value;
        ++size;
        sort(data,data+size);
    }
}
void Set::remove(int value)
{
    int pos=b_search(value);
    if (pos!=-1)
    {
        int i;
        --size;
        for (i=pos;i<size;++i) data[i]=data[i+1];
    }
}
istream& operator>>(istream& in,Set& s)
{
    int t;
    for (int i=0;i<s.schedule;++i)
    {
        in>>t;
        s.insert(t);
    }
    sort(s.data,s.data+s.size);
    return in;
}
ostream& operator<<(ostream& out,const Set& s)
{
    sort(s.data,s.data+s.size);
    for (int i=0;i<s.size;++i) out<<s.data[i]<<' ';
    out<<'\n';
    return out;
}
Set& Set::operator+=(const Set& other)
{
    for (int i=0;i<other.size;++i) insert(other.data[i]);
}
Set& Set::operator-=(const Set& other)
{
    for (int i=0;i<other.size;++i) remove(other.data[i]);
}
Set& Set::operator*=(const Set& other)
{
    Set tmp(0);
    for (int i=0;i<other.size;++i) if (b_search(other.data[i])!=-1) tmp.insert(other.data[i]);
    (*this)=tmp;
}
int main()
{
    int n,i,t;
    Set **ss=new Set*[100];
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>t;
        ss[i]=new Set(t);
    }
    for (i=0;i<n;++i) cin>>(*ss[i]);
    int m,x,y;
    char tt;
    cin>>m;
    for (i=0;i<m;++i)
    {
        cin>>tt>>x>>y;
        if (tt=='+')
        {
            *ss[x-1] += *ss[y-1];
        }
        if (tt=='-')
        {
            *ss[x-1] -= *ss[y-1];
        }
        if (tt=='*')
        {
            *ss[x-1] *= *ss[y-1];
        }
    }
    for (i=0;i<n;++i) cout<<(*ss[i]);
    for (i=0;i<n;++i) delete ss[i];
    delete [] ss;
}

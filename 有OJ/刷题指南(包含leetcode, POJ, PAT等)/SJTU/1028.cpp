#include <iostream>
#include <cstring>
//#include <fstream>
using namespace std;
int out(int* data,int l,int r)
{
    int t=1,i=l;
    ++i;
    while (t>0 && i<=r)
    {
        if (data[i]==1) ++t;
        else if (data[i]==2) --t;
        ++i;
    }
    return i;
}
bool check2(int* data,int l,int r)
{
    if (l>r) return true;
    if (l==r)
    {
        if (data[l]==3) return true;
        else return false;
    }
    int i,t=0;
    for (i=l;i<=r;++i)
    {
        if (data[i]==3) ++t;
        else if (data[i]==4) --t;
        else if (data[i]==1) i=out(data,i,r)-1;

        if (t<0) return false;
    }
    return true;
}
bool check(int* data,int n)
{
    int s[100],t=0,i=0;
    while (i<n && data[i]!=1 && data[i]!=2) ++i;
    while (i<n)
    {
        if (data[i]==1)
        {
            s[t]=i;
            ++t;
        } else if (data[i]==2)
        {
            --t;
            if (t<0) return false;
            if (!check2(data,s[t]+1,i-1)) return false;
        }
        ++i;
        while (i<n && data[i]!=1 && data[i]!=2)0 ++i;
    }
    if (t>0) return false;
    return check2(data,0,n-1);
}
int main()
{
    //ifstream fin("1028.in");
    int data[100]={0},n,i,t=0;
    char s[6];
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>s;
        if (strcmp(s,"begin")==0) data[t]=1;
        else if (strcmp(s,"end")==0) data[t]=2;
        else if (strcmp(s,"if")==0)
        {
            if (i==n-1)
            {
                cout<<"NO\n";
                return 0;
            }
            else
            {
                cin>>s;
                ++i;
                if (strcmp(s,"then")==0) data[t]=3;
                else
                {
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
        else if (strcmp(s,"else")==0) data[t]=4;
        ++t;
    }
    //if (data[0]!=1)
    //for (i=0;i<t;++i) cout<<data[i]<<endl;
    if (check(data,t)) cout<<"YES\n";else cout<<"NO\n";
    //fin.close();
}

#include <iostream>
#include <fstream>
using namespace std;
char file[4098];
int data[2048];
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
        while (i<n && data[i]!=1 && data[i]!=2) ++i;
    }
    if (t>0) return false;
    return check2(data,0,n-1);
}
int main()
{
    //ifstream fin("1206.in");
    file[0]=' ';
    int i=0,j=0,len=1,num=0;
    char t;
    while (cin.get(t))
    {
        if (t=='\n')
        {
            file[len]=' ';
            ++len;
        }
        else if (t=='\'')
        {
            while (cin.get(t) && t!='\'');
        } else
        {
            if ('A'<=t && t<='Z') t=t-'A'+'a';
            file[len]=t;
            ++len;
        }
    }
    file[len]=' ';
    ++len;
    while (i<len)
    {
        while (file[i]!=' ' && i<len) ++i;
        if (i<=len-7 && file[i]==' ' && file[i+1]=='b' && file[i+2]=='e' && file[i+3]=='g' && file[i+4]=='i' && file[i+5]=='n' && file[i+6]==' ')
        {
            if (num>0 && data[num-1]==-3)
            {
                cout<<"Error!\n";
                return 0;
            }
            data[num]=1;
            ++num;
            i+=6;
        }else if (i<=len-5 && file[i]==' ' && file[i+1]=='e' && file[i+2]=='n' && file[i+3]=='d' && file[i+4]==' ')
        {
            if (num>0 && data[num-1]==-3)
            {
                cout<<"Error!\n";
                return 0;
            }
            data[num]=2;
            ++num;
            i+=4;
        }else if (i<=len-4 && file[i]==' ' && file[i+1]=='i' && file[i+2]=='f' && file[i+3]==' ')
        {
            if (num>0 && data[num-1]==-3)
            {
                cout<<"Error!\n";
                return 0;
            }
            data[num]=-3;
            ++num;
            i+=3;
        }else if (i<=len-6 && file[i]==' ' && file[i+1]=='t' && file[i+2]=='h' && file[i+3]=='e' && file[i+4]=='n' && file[i+5]==' ')
        {
            if (num==0 || data[num-1]!=-3)
            {
                cout<<"Error!\n";
                return 0;
            }
            data[num-1]=3;
            i+=5;
        }else if (i<=len-6 && file[i]==' ' && file[i+1]=='e' && file[i+2]=='l' && file[i+3]=='s' && file[i+4]=='e' && file[i+5]==' ')
        {
            if (num>0 && data[num-1]==-3)
            {
                cout<<"Error!\n";
                return 0;
            }
            data[num]=4;
            ++num;
            i+=5;
        } else ++i;
    }
    if (check(data,num)) cout<<"Match!\n";else cout<<"Error!\n";
    //fin.close();
}

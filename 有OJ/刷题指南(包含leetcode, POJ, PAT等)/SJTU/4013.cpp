#include <cstdio>
#include <queue>
#include <string>
using namespace std;
const int BASE=500009;
class hash
{
private:
    int *data;
public:
    hash()
    {
        data=new int[500009];
        for (int i=0;i<500009;++i) data[i]=-1;
    }
    ~hash(){delete [] data;}
    int cal(int n)
    {
        return n%BASE;
    }
    void insert(int n)
    {
        int t=cal(n),k=0;
        while (data[(t+k*k)%BASE]!=-1) ++k;
        data[(t+k*k)%BASE]=n;
    }
    bool find(int n)
    {
        int t=cal(n),k=0;
        while (data[(t+k*k)%BASE]!=-1)
        {
            if (data[(t+k*k)%BASE]==n) return true;
            else ++k;
        }
        return false;
    }
};
int A(int n)
{
    return (n%10000)*10000+n/10000;
}
int B(int n)
{
    int a=n/10000,b=n%10000;
    a=(a%10)*1000+a/10;
    b=(b%10)*1000+b/10;
    return a*10000+b;
}
int C(int n)
{
    int a=n/10000000;
    n%=10000000;
    int b=n/1000000;
    n%=1000000;
    int c=n/100000;
    n%=100000;
    int d=n/1000;
    n%=1000;
    int e=n/100;
    n%=100;
    int f=n/10;
    n%=10;
    return a*10000000+e*1000000+b*100000+d*1000+f*100+c*10+n;
}
void disp(const string& s)
{
    int l=s.length();
    printf("%d",l);
    for (int i=0;i<l;++i)
    {
        if (i%60==0) printf("\n");
        printf("%c",s[i]);
    }
}
int main()
{
    int a,b,c,d,e,f,g,h,goal;
    scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
    goal=a*10000000+b*1000000+c*100000+d*10000+h*1000+g*100+f*10+e;
    queue<int> q1;
    queue<string> q2;
    string t="";
    hash hs;
    hs.insert(12348765);
    q1.push(12348765);
    q2.push("");
    while (!q1.empty())
    {
        a=q1.front();
        q1.pop();
        t=q2.front();
        q2.pop();
        if (a==goal)
        {
            disp(t);
            return 0;
        }
        b=A(a);
        if (!hs.find(b))
        {
            q1.push(b);
            q2.push(t+"A");
        }
        b=B(a);
        if (!hs.find(b))
        {
            q1.push(b);
            q2.push(t+"B");
        }
        b=C(a);
        if (!hs.find(b))
        {
            q1.push(b);
            q2.push(t+"C");
        }
    }
}

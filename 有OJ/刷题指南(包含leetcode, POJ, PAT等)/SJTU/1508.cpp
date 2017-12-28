#include <iostream>
#include <cstring>
using namespace std;
struct student
{
    char name[30];
    int score,grade;
    bool ganbu,xibu;
    int papers;
};
void input(student& sb)
{
    cin>>sb.name>>sb.score>>sb.grade;
    char s[10];
    cin>>s;
    sb.ganbu=(strcmp(s,"Y")==0);
    cin>>s;
    sb.xibu=(strcmp(s,"Y")==0);
    cin>>sb.papers;
}
int award(student& sb)
{
    int res=0;
    if (sb.score>80 && sb.papers>0) res+=8000;
    if (sb.score>85 && sb.grade>80) res+=4000;
    if (sb.score>90) res+=2000;
    if (sb.score>85 && sb.xibu) res+=1000;
    if (sb.grade>80 && sb.ganbu) res+=850;
    return res;
}
int main()
{
    student ss[100];
    int i,n,sum=0,max=0,m,t;
    cin>>n;
    for (i=0;i<n;++i)
    {
        input(ss[i]);
        t=award(ss[i]);
        sum+=t;
        if (t>max)
        {
            m=i;
            max=t;
        }
    }
    cout<<ss[m].name<<'\n'<<max<<'\n'<<sum<<'\n';
}

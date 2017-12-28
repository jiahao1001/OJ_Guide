#include <iostream>
#include <cstring>
using namespace std;
class article
{
private:
    char data[101][2001];
    int length[101];
    int lineNum;
public:
    article();
    void addLine(const char *s);
    void list(int start,int end);
    void ins(int line,int colomn,const char *s);
    void del(int line,int colomn,int del_len);
    void print(){if (lineNum>0) (*this).list(1,lineNum);}
};
article::article()
{
    lineNum=0;
}
void article::addLine(const char *s)
{
    strcpy(data[lineNum],s);
    length[lineNum]=strlen(s);
    ++lineNum;
}
void article::list(int start,int end)
{
    if ((start<=0)||(end>lineNum)||(start>end)||(end<=0)||(start>lineNum))
    {
        cout<<"Error!"<<endl;
        return;
    }
    for (int i=start-1;i<end;++i) cout<<data[i]<<endl;
}
void article::ins(int line,int colomn,const char *s)
{
    if ((line<=0)||(line>lineNum)||(colomn<=0)||(colomn>length[line-1]+1))
    {
        cout<<"Error!"<<endl;
        return;
    }
    int i,l=strlen(s);
    for (i=length[line-1];i>=colomn-1;--i) data[line-1][i+l]=data[line-1][i];
    for (i=0;i<l;++i) data[line-1][i+colomn-1]=s[i];
    length[line-1]+=l;
}
void article::del(int line,int colomn,int del_len)
{
    if ((line<=0)||(line>lineNum)||(colomn<=0)||(colomn>length[line-1])||(colomn+del_len-1>length[line-1]))
    {
        cout<<"Error!"<<endl;
        return;
    }
    for (int i=colomn-1;i<length[line-1]-del_len;++i) data[line-1][i]=data[line-1][i+del_len];
    data[line-1][length[line-1]-del_len]='\0';
    length[line-1]-=del_len;
}
int main()
{
    char s[2000];article art;int a,b,c;
    char st[100];
    cin.getline(s,2000);
    while (strcmp(s,"******")!=0)
    {
        art.addLine(s);
        cin.getline(s,2000);
    }
    cin>>s;
    while (strcmp(s,"quit")!=0)
    {
        if (strcmp(s,"list")==0)
        {
            cin>>a>>b;
            art.list(a,b);
        } else if (strcmp(s,"ins")==0)
        {
            cin>>a>>b;
            cin.get();
            cin.getline(st,100);
            art.ins(a,b,st);
        } else if (strcmp(s,"del")==0)
        {
            cin>>a>>b>>c;
            art.del(a,b,c);
        }
        cin>>s;
    }
    art.print();
}

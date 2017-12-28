#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a[400]={0},b[400]={0},c[800]={0},la,lb,lc,i,j;
    char s[400];
    cin>>s;
    la=strlen(s);
    for (i=0;i<la;++i) a[i]=s[la-1-i]-'0';
    cin>>s;
    lb=strlen(s);
    for (i=0;i<lb;++i) b[i]=s[lb-1-i]-'0';
    for (i=0;i<la;++i) for (j=0;j<lb;++j) c[i+j]+=a[i]*b[j];
    lc=la+lb-1;
    for (i=0;i<lc;++i)
    {
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while (c[lc]!=0)
    {
        c[lc+1]+=c[lc]/10;
        c[lc]%=10;
        ++lc;
    }
    for (i=lc-1;i>=0;--i) cout<<c[i];
}

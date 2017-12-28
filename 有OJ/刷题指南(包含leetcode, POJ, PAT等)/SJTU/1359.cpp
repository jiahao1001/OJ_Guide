#include <iostream>
#include <cstring>
using namespace std;
int cv(char t)
{
    if ((t>='A')&&(t<='Z')) return (t-'A'+1);
    if ((t>='a')&&(t<='z')) return (t-'a'+27);
    if (t==' ') return 0;
}
int main()
{
    char s[1001];
    cin.getline(s,1001);
    int l=strlen(s),i;long long res=0;
    for (i=0;i<l;++i) if (s[i]!=' ') res+=(i+1)*cv(s[i]);
    cout<<res;
}

#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n,l,i,j,t;
    char s[111];
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>s;
        l=strlen(s);
        if (l%2==1) cout<<"NO\n";
        else
        {
            t=0;
            for (j=0;j<l;++j)
            {
                if (s[j]=='(') ++t;
                else if (s[j]==')')
                {
                    --t;
                    if (t<0) break;
                }
            }
            if (t==0) cout<<"YES\n";else cout<<"NO\n";
        }
    }
}

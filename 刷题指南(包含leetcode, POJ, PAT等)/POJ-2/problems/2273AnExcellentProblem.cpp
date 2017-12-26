#include<iostream>
using namespace std;
int digit[20];
int cnt;
int main()
{
    long long n,m;
    char c;
    while(cin>>c>>m>>c>>n,n||m)
    {
        for(cnt=0;n;cnt++) digit[cnt]=n%26,n/=26;
        int borrow=0;
        for(int i=0;i<cnt;i++)
            if(digit[i]+borrow<=0)
            {
                digit[i]+=borrow+26;
                borrow=-1;
            }else
            {
                digit[i]+=borrow;
                borrow=0;
            }
        
        if(cnt>1&&digit[cnt-1]==26) cnt--;
        for(int i=cnt-1;i>=0;i--)
            cout<<(char)(digit[i]+'A'-1);
        cout<<m<<endl;
    }
    return 0;
}

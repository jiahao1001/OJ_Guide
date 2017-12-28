#include <iostream>
using namespace std;
int n,k;
int main()
{
    cin>>n>>k;
    if(n<=k)
    {
        cout<<0;
        return 0;
    }
    int count=0;
    for(int i=0;i<30;i++)
    {
        if(n&(1<<i))
            count++;
    }
    if(count<=k)
    {
        cout<<0;
        return 0;
    }
    int m=0;
    for(int i=29;i>=0;i--)
    {
        if(n&(1<<i))
        {
            if(k!=1)
            {
                m+=(1<<i);
                k--;
            }
            else
            {
                i++;
                m+=(1<<i);
                break;
            }
        }
    }
    cout<<m-n;
}

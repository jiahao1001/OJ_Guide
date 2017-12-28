#include <iostream>
using namespace std;
int main()
{
    long long n,i,s=0,t,max=0,start=0;
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>t;
        s+=t;
        if (s<0)
        {
            s=0;
            start=i+1;
        }
        else if ((s>max)&&(start<i)) max=s;
    }
    if ((max>0)&&(n>1)) cout<<max;else cout<<"Game Over";
}

#include <iostream>
using namespace std;
int main()
{
    int s,t,i,j,max=1,p;
    cin>>s>>t;
    int *dp=new int[t-s+1],*pis=new int[t-s+1];
    //dp[0]=1;
    for (i=s;i<=t;++i)
    {
        dp[i-s]=1;
        pis[i-s]=1;
        for (j=s;j<i;++j) if ((i*100)%j==0)
        {
            if (dp[i-s]<=dp[j-s])
            {
                dp[i-s]=dp[j-s]+1;
                pis[i-s]=1;
            }else if (dp[i-s]==dp[j-s]+1) ++pis[i-s];
        }
        if (dp[i-s]>max)
        {
            max=dp[i-s];
            p=pis[i-s];
        } else if (dp[i-s]==max) p+=pis[i-s];
    }
    cout<<max<<endl<<p;
    delete [] dp;

}

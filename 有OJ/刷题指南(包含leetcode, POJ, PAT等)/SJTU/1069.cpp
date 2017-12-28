#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
bool price[100010]={0};
int amount[100010]={0};
int A[100];
int C[100];
int test(int n,int m)
{
    memset(price,0,sizeof(price));
    int i,j,k,res=0;
    for (i=0;i<n;++i) scanf("%d",&A[i]);
    for (i=0;i<n;++i) scanf("%d",&C[i]);
    price[0]=true;
    for (i=0;i<n;++i)
    {
        memset(amount,0,sizeof(amount));
        for (j=1;j<=m;++j) if (!price[j] && j>=A[i] && price[j-A[i]] && amount[j-A[i]]<C[i])
        {
            ++res;
            price[j]=true;
            amount[j]=amount[j-A[i]]+1;
        }
    }
    return res;
}
int main()
{
    scanf("%d %d",&n,&m);
    while (n!=0 || m!=0)
    {
        printf("%d\n",test(n,m));
        scanf("%d %d",&n,&m);
    }
}

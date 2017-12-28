#include <iostream>
#include <cmath>
using namespace std;
bool prime(int& n)
{
    if (n<2) return false;
    if (n<4) return true;
    if (n==4) return false;
    int qq=floor(sqrt(n)+0.5)+1;
    for (int i=2;i<qq;++i) if (n%i==0) return false;
    return true;
}
void dis(int n,int& p)
{
    if (prime(n))
    {
        cout<<n<<"(1)\n";
        return;
    }
    int t=0;
    while (n%p!=0) ++p;
    while (n%p==0)
    {
        ++t;
        n/=p;
    }
    cout<<p<<'('<<t<<')';
    dis(n,p);
}
int main()
{
    int n;
    cin>>n;
    cout<<n<<'=';
    int p=2;
    dis(n,p);
}

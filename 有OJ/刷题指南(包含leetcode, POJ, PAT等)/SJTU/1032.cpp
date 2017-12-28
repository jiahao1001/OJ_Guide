#include <iostream>
using namespace std;
unsigned long pow(int a,int b)
{
    int i;unsigned long p=a;
    for (i=1;i<b;++i) p*=a;
    return p;
}
int main()
{
    int m,n;
    cin>>m>>n;
    switch (m)
    {
        case 0:cout<<n+1;
               break;
        case 1:cout<<n+2;
               break;
        case 2:cout<<n*2+3;
               break;
        case 3:cout<<(pow(2,n+3)-3);
    }
}

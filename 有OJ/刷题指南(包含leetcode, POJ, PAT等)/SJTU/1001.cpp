#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d=0;
    cin>>a>>b>>c;
    a+=b;
    for (int i=0;i<c;++i)
    {
        cin>>b;
        if (b<=a) ++d;
    }
    cout<<d;
}

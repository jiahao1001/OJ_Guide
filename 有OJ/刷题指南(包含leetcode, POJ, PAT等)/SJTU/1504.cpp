#include <iostream>
using namespace std;
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if (a>b)
    {
        a=a+b;
        b=a-b;
        a=a-b;
    }
    if (a>c)
    {
        a=a+c;
        c=a-c;
        a=a-c;
    }
    if (b>c)
    {
        b=b+c;
        c=b-c;
        b=b-c;
    }
    if (a+b<=c) cout<<"not triangle";
    else if (a*a+b*b==c*c) cout<<"right-angled triangle";
    else cout<<"triangle";
}

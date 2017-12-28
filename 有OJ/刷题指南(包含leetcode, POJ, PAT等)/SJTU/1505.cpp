#include <iostream>
using namespace std;
int main()
{
    char t;cin>>t;
    if ((('a'<=t)&&(t>='w'))||(('A'<=t)&&(t>='W'))) t+=3;else t-=23;
    cout<<t;
}

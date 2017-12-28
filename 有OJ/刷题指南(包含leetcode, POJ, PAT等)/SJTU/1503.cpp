#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double a,b,c,d;
    cin>>a>>b>>c>>d;
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    cout<<sqrt((a-c)*(a-c)+(b-d)*(b-d));
}

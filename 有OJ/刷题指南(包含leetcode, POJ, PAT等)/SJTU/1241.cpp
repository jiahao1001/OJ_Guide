#include <iostream>
using namespace std;
double cv(int g)
{
    if (g>=95) return 4.3;
    if (g>=90) return 4.0;
    if (g>=85) return 3.7;
    if (g>=80) return 3.3;
    if (g>=75) return 3.0;
    if (g>=70) return 2.7;
    if (g>=67) return 2.3;
    if (g>=65) return 2.0;
    if (g>=62) return 1.7;
    if (g>=60) return 1.0;
}
int main()
{
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    int n,t,i;double sum=0;
    cin>>n;
    for (i=0;i<n;++i)
    {
        cin>>t;
        sum+=cv(t);
    }
    sum/=n;
    cout<<sum;
}

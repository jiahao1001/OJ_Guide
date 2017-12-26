#include <iostream>
using namespace std;
/*
获取n的约数个数。
约定n>=1
*/
int getNumDivisor(int n)
{
    int c=0,i;
    for(i=1;i*i<n;i++)
    {
        if(n%i==0)c+=2;
    }
    if(i*i==n)c+=1;
    return c;
    
}
int main()
{
    int n;
    cin >> n;
    cout << getNumDivisor(n) << endl;
    return 0;
}
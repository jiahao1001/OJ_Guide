#include <iostream>
#include <algorithm>
using namespace std;
// 计算F(n)和F(n+1)除m的余数，分别放入fn和fn1中。
void calcF(int n, int m, int &fn, int &fn1)
{
    if(n==1)
    {
        fn=1;
        fn1=1;
        return;
    }

    if(n%2==0)
    {
        int f,f1;
        calcF(n/2,m,fn,fn1);
        f=fn;f1=fn1;
        fn=(f1*f+f*(f1-f+m))%m;
        fn1=(f1*f1+f*f)%m;
    }

    else
    {
        int f,f1;
        calcF((n-1)/2,m,fn,fn1);
        f=(fn1*fn1+fn*fn)%m;
        calcF((n+1)/2,m,fn,fn1);
        f1=(fn1*fn+fn*(fn1-fn+m))%m;
        fn=f;
        fn1=f1;
    }


}
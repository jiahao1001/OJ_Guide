#include<iostream>
#include<stdio.h>
#include<map>
#include<algorithm>
using namespace std;

inline int cube(int x)
{
    return x*x*x;
}

int a[5];
int app[1000000];
int n;
int main()
{
    for(int i=0;i<5;i++)
        scanf("%d",a+i);
    int sol=0;
    for(int i=-50;i<=50;i++)
        for(int j=-50;j<=50;j++)
            for(int k=-50;k<=50;k++)
                if(i&&j&&k){
                    app[n++]=cube(i)*a[0]+cube(j)*a[1]+cube(k)*a[2];
                }
    sort(app,app+n);
    for(int i=-50;i<=50;i++)
        for(int j=-50;j<=50;j++)
            if(i&&j)
            {
                int tmp=-1*(cube(i)*a[3]+cube(j)*a[4]);
                sol+=upper_bound(app,app+n,tmp)-lower_bound(app,app+n,tmp);
                
            }
    printf("%d\n",sol);
    return 0;
}

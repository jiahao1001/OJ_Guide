#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t,len,n;
    cin>>t;
    while(t--)
    {
        int e=0,f=0;
        int a;
        cin>>len>>n;
        for(int i=0;i<n;i++)
            cin>>a,e=max(e,min(a,len-a)),f=max(f,max(a,len-a));
        cout<<e<<" "<<f<<endl;
    }
    return 0;
}

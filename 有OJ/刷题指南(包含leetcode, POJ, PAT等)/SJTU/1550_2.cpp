#include <iostream>
#include <stdio.h>
using namespace std;
int l[10001];
int r[10001];
int count=0;
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=10000;i++)
    {
        l[i]=r[i]=0;
    }
    int x;
    char c;
    int low=0;
    char ttt[100];
   cin.getline(ttt,100,'\n');
   scanf("%c",&c);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        //cout<<c;
        scanf("%c",&c);
        //cout<<x;
        count+=x;
        for(int j=1;j<=x;j++)
        {
            r[j]=i;

            if(l[j]==0)
                l[j]=i;

        }
    }
    //cout<<endl;
    int tmp=0;
    for(int i=1;i<=10000;i++)
    {
        //cout<<count[i]<<endl;
        if(l[i]==0)
            break;
        tmp+=r[i]-l[i]+1;
    }
    cout<<tmp-count;

}

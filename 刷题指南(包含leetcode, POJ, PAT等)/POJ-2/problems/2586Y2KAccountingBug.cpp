#include<iostream>
#include<stdio.h>
using namespace std;
int s,d;
int best;
int surplus[12];
void dfs(int cur)
{
    if(cur==12){
        int total=0;
        int sum=0;
        for(int i=0;i<5;i++)
            total+=surplus[i];
        if(total>=0) return;
        sum=total;
        for(int i=5;i<12;i++){
            total+=surplus[i]-surplus[i-5];
            sum+=surplus[i];
            if(total>=0) return;
        }
        best=max(best,sum);
        return;
    }
    surplus[cur]=s;
    dfs(cur+1);
    surplus[cur]=-d;
    dfs(cur+1);
}
int main()
{
    while(cin>>s>>d)
    {
        best=0;
        dfs(0);
        if(best==0) cout<<"Deficit"<<endl;
        else cout<<best<<endl;
    }
    return 0;
}

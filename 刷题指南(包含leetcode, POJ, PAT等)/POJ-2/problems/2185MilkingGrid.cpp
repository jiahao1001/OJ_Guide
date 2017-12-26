#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
char cow_h[10000][80];
char cow_v[75][10010];
int h[10000],v[75];
int R,C;
int fail[10010];
int get_tile(char *s)
{
    //cout<<s<<endl;
    int n=strlen(s);
    int i,j=0;
    fail[1]=0;
    for(i=2;i<=n;i++)
    {
        while(j>0 && s[j+1-1]!=s[i-1]) j=fail[j];
        if(s[j+1-1]==s[i-1]) j++;
        fail[i]=j;
    }
    /*for(int i=0;i<=n;i++)
        printf("%d ",fail[i]);
    cout<<endl;
    cout<<n-fail[n]<<endl;*/
    return n-fail[n];
}
inline int gcd(int a,int b)
{
    if(!b) return a;
    return gcd(b,a%b);
}
inline long long lcm(int A[],int n,int lim){
    
    int a=A[0];
    if(a>=lim) return lim;
    int b;
    int g;
    for(int i=1;i<n;i++){
        b=A[i];
        g=gcd(a,b);
        a=(a/g)*(b/g)*g;
        if(a>=lim) return lim;
    }
    return a;
    
}
int main()
{
    scanf("%d%d",&R,&C);
    for(int i=0;i<R;i++)
        scanf("%s",cow_h[i]);
    for(int i=0;i<C;i++)
    {
        for(int j=0;j<R;j++)
            cow_v[i][j]=cow_h[j][i];
        cow_v[i][R]=0;
    }
    for(int i=0;i<R;i++)
        h[i]=get_tile(cow_h[i]);
    for(int i=0;i<C;i++)
        v[i]=get_tile(cow_v[i]);
    
    printf("%d\n",lcm(h,R,C)*lcm(v,C,R));
    return 0;
}


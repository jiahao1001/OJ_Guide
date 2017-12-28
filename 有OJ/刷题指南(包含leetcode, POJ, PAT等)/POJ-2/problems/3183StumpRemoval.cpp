#include<iostream>
#include<math.h>
#include<algorithm>
#include<limits.h>
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>
using namespace std;
const int N = 50010;
int h[N];
int n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",h+i);
    }
    for(int i=1;i<=n;i++){
        if((i-1==0 || h[i-1]<=h[i]) && (i+1==n+1 || h[i+1]<=h[i])) printf("%d\n",i);
    }
    return 0;
}

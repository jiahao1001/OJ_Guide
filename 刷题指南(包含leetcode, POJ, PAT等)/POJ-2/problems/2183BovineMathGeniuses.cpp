#include<iostream>
#include<stdio.h>
#include<string.h>
#include<utility>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#include<limits.h>
using namespace std;
int main()
{
    map<int,int> dist;

    int	n;
    scanf("%d",&n);
    for(int d=1;;d++){
        n = (n/10)%10000;
        n*=n;
        n%=1000000;
        if(dist.count(n)){
            printf("%d %d %d\n",n,d-dist[n],d);
            return 0;
        }
        dist[n] = d;

    }

    return 0;
}


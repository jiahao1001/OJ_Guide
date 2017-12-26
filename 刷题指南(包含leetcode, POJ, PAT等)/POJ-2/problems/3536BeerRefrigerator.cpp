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
int n;
int main()
{
    scanf("%d",&n);
    int best = INT_MAX;
    int a,b,c;
    for(int x=1;x*x<=n;x++)
        if(n%x==0){
            int t = n/x;
            for(int y=1;y*y<=t;y++)
                if(t%y==0){
                    int z = t/y;
                    if(2*(x*y+x*z+y*z)<best){
                        best = 2*(x*y+x*z+y*z);
                        a=x,b=y,c=z;
                    }
                }
        }
    printf("%d %d %d\n",a,b,c);
    return 0;
}

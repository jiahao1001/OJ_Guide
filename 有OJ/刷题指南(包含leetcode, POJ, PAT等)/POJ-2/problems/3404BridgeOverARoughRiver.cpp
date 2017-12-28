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
const int N = 1017;
int n;
int t[N];
int main()
{
    while(~scanf("%d",&n)){
        for(int i=0;i<n;i++)
            scanf("%d",t+i);
        sort(t,t+n);
        int total = 0;
        while(n>=4){
            if(2*t[1]<t[0]+t[n-2]){
                total+=t[0]+2*t[1]+t[n-1];
                n-=2;
            }
            else {
                total+=2*t[0]+t[n-2]+t[n-1];
                n-=2;
            }
        }
        if(n<=2){
            printf("%d\n",total+t[n-1]);
        }else if(n==3){
            printf("%d\n",total+t[0]+t[1]+t[2]);
        }
    }
    return 0;
}

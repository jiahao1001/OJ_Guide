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
int x[1000];
int R,n;
int main()
{
    while(scanf("%d%d",&R,&n),R!=-1){
        for(int i=0;i<n;i++)scanf("%d",x+i);
        sort(x,x+n);
        n = unique(x,x+n)-x;
        int d = 0;
        int stone = 0;
        int j=0;
        while(j<n){
            while(j+1<n && (d+=x[j+1]-x[j])<=R) j++;
            if(j+1==n) stone ++,j++;
            else{
                d = 0;
                stone++;
                while(j+1<n && (d+=x[j+1]-x[j])<=R) j++;
                j++;
                d=0;
            }
        }
        printf("%d\n",stone);
    }
    return 0;
}

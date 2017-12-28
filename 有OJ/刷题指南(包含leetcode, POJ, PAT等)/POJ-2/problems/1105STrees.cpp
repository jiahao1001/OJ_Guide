#include<iostream>
#include<stdio.h>
#include<vector>
#include<limits.h>
#include<string.h>
using namespace std;
int n,m;
int v[7];
char o[10];
char s[1050];
char b[10];
int main()
{
    int q=1;
    int x;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
            scanf("%s",b);
            x = atoi(b+1);
            v[i] = x-1;
        }
        scanf("%s",s);
        //printf("%s\n",s);
        scanf("%d",&m);
        printf("S-Tree #%d:\n",q++);
        for(int i=0;i<m;i++){
            scanf("%s",o);
            int l=0,r = 1<<n;
            int mid;
            for(int j=0;j<n;j++){
                mid = (l+r)/2;
                if(o[v[j]]=='0') r = mid;
                else l=mid;
                //printf("%d,%d\n",l,r);
            }
            printf("%c",s[l]);
        }
        printf("\n\n");
    }
    return 0;
}

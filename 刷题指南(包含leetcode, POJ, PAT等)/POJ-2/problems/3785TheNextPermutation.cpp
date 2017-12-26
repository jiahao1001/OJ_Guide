#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    int P,k;
    scanf("%d",&P);
    char s[100];
    while(P--){
        scanf("%d %s",&k,s);
        int n = strlen(s);
        int ii = -1;
        for(int i=n-1;i>0;i--)
            if(s[i]>s[i-1]){
                ii = i;
                break;
            }
        printf("%d ",k);
        if(ii==-1)printf("BIGGEST\n");
        else{
            int best = '9';
            int x;
            for(int i=ii;i<n;i++)
                if(s[i]>s[ii-1] && best>=s[i]) best = s[i],x=i;
            swap(s[ii-1],s[x]);
            sort(s+ii,s+n);
            printf("%s\n",s);
        }
    }
    return 0;
}

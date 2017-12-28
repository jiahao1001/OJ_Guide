#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int p[100];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",p+i);
        // id = -1;
        int id = -1;
        int cur = 0,cnt = 0;
        while(id!=m){
            id = -1;
            int high = -1;
            for(int i=cur,j=0;j<n;j++,i=(i+1)%n)
                if(p[i] && p[i]>high) high = p[i],id=i;
            p[id] = 0;
            cnt++;
            cur = (id+1)%n;
        }
        printf("%d\n",cnt);
        
    }
    return 0;
}

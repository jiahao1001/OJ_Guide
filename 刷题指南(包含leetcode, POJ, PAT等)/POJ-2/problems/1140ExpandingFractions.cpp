#include<stdio.h>
#include<string.h>
int vis[1000];
int q[1000];
int n,m;
int main()
{
    while(scanf("%d%d",&n,&m),n||m){
        for(int i=0;i<m;i++) vis[i] = -2;
        int d=0;
        int rep = 0;
        vis[n] = -1;
        for(;;d++){
            n*=10;
            q[d] = n/m;
            n%=m;
            if(vis[n]!=-2){
                rep = d-vis[n];
                break;
            }
            vis[n] = d;
            if(n==0) break;
        }
        printf(".");
        for(int i=0;i<=d;i++){
            printf("%d",q[i]);
            if( (i+2)%50==0 || (i==d && (i+2)%50)) printf("\n");
        }

        if(n==0) printf("This expansion terminates.\n");
        else printf("The last %d digits repeat forever.\n",rep);
    }
    return 0;
}

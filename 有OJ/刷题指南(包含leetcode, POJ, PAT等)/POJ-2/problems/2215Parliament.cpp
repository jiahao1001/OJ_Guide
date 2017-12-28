#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int sc[1001][1001];
int A[1001][1001];
int query(int x1,int y1,int x2,int y2){
    return A[x2][y2]-A[x1-1][y2] -A[x2][y1-1] + A[x1-1][y1-1];
}
int main()
{
    int t,r,s;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&r,&s);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=s;j++)
                scanf("%d",&sc[i][j]);
        memset(A,0,sizeof A);
        for(int i=1;i<=r;i++)
            for(int j=1;j<=s;j++)
                A[i][j] = sc[i][j] +A[i-1][j] + A[i][j-1] - A[i-1][j-1];
        int k,x1,y1,x2,y2;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            printf("Absolutni hodnota pohodlnosti je %d bodu.\n",query(x1,y1,x2,y2));
        }
        printf("\n");
        
    }
    return 0;
}

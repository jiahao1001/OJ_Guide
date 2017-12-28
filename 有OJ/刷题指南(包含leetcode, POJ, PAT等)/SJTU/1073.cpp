#include <cstdio>
int n;
int beads[210];
int res[210][210]={0};
int main()
{
    int i,j,k;
    scanf("%d",&n);
    for (i=1;i<=n;++i)
    {
        scanf("%d",&beads[i]);
        beads[n+i]=beads[i];
    }
    beads[0]=beads[n];
    beads[2*n+1]=beads[1];
    for (i=0;i<2*n;++i) res[i][i+1]=beads[i]*beads[i+1]*beads[i+2];
    for (i=3;i<=n;++i) for (j=0;j<2*n+2-i;++j) for (k=1;k<i;++k)
        if (res[j][j+i-1] < res[j][j+k-1]+res[j+k][i+j-1]+beads[j]*beads[j+k]*beads[i+j]) res[j][j+i-1]=res[j][j+k-1]+res[j+k][i+j-1]+beads[j]*beads[j+k]*beads[i+j];
    int ans=0;
    for (i=0;i<n;++i) if (res[i][i+n-1]>ans) ans=res[i][i+n-1];
    printf("%d\n",ans);
}

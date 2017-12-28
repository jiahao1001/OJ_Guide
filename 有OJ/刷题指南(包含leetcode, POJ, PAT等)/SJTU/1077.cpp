#include <cstdio>
int sum[31][31]={0};
int root[31][31]={0};
void print(int l,int r){
     if (l>r) return;
     printf("%d ",root[l][r]);
     print(l,root[l][r]-1);
     print(root[l][r]+1,r);
}
int main()
{
    int value[31];
    int n,i,j,k;
    scanf("%d",&n);
    for (i=1;i<=n;++i)
    {
        scanf("%d",&value[i]);
        for (j=0;j<i;++j) sum[i][j]=1;
        sum[i][i]=value[i];
        root[i][i]=i;
    }
    for (i=1;i<n;++i) for (j=1;j<=n-i;++j) for (k=j;k<=i+j;++k)
    {
        if (sum[j][k-1]*sum[k+1][i+j]+value[k]>sum[j][i+j])
        {
            sum[j][i+j]=sum[j][k-1]*sum[k+1][i+j]+value[k];
            root[j][i+j]=k;
            //printf("%d %d %d %d\n",j,i+j,k,sum[j][i+j]);
        }
    }
    printf("%d\n",sum[1][n]);
    print(1,n);
}

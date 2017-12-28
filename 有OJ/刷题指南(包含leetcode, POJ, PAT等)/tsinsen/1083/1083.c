#include <stdio.h>

double A[10][10];
double b[10];
double x[10];

void swap(int p, int q, int n)
{
    int i;
    double tmp;
    for(i=0;i<n;i++)
    {
        tmp=A[p][i];
        A[p][i]=A[q][i];
        A[q][i]=tmp;
    }
    tmp=b[p];b[p]=b[q];b[q]=tmp;
}

int main()
{
    int i,j,k,n,p,q;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%lf",&A[i][j]);
    for(i=0;i<n;i++)scanf("%lf",&b[i]);


    for(i=0;i<n;i++)
    {
        int max=i;
        for(j=i+1;j<n;j++)
            if(A[j][i]>A[max][i])max=j;
        if(A[max][i]==0)continue;
        if(max!=i)swap(i,max,n); 

        double t=A[i][i]; 
        for(j=i;j<n;j++)A[i][j]/=t;
        b[i]/=t;

        for(j=i+1;j<n;j++)
        {
            double t=A[j][i];
            for(k=i;k<n;k++)A[j][k]-=t*A[i][k];
            b[j]-=t*b[i];
        }

    }

    for(i=n-1;i>=0;i--)
    {
        for(j=i+1;j<n;j++)
        {
            b[i]-=A[i][j]*x[j];
        }
        x[i]=b[i];
    }

    for(i=0;i<n;i++)
    {
        printf("%.2lf\n",x[i]);
    }

    return 0;
}
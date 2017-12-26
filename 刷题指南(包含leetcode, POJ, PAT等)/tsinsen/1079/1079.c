#include <stdio.h>
#include <string.h>

int p[5];   //存放当前1到5的排列
int A[5][5];

//获取逆序对个数
int reverse()
{
    int i,j,c=0;
    for(i=0;i<4;i++)
        for(j=i+1;j<5;j++)
            if(p[i]>p[j])c++;
    return c;
}

//检测排列中是否有重复数字
bool fun()
{
    int i,j;
    for(i=0;i<=3;i++)
        for(j=i+1;j<=4;j++)
            if(p[i]==p[j])return false;
    return true;
}

int main()
{
    memset(A,0,sizeof(A));
    int i,j,n,s=0;
    for(i=0;i<5;i++)A[i][i]=1;

    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&A[i][j]);

    for(p[0]=1;p[0]<=5;p[0]++)
        for(p[1]=1;p[1]<=5;p[1]++)
            for(p[2]=1;p[2]<=5;p[2]++)
                for(p[3]=1;p[3]<=5;p[3]++)
                    for(p[4]=1;p[4]<=5;p[4]++)
                    {
                        if(!fun())continue;

                        int t=reverse();
                        int m=1;
                        for(i=0;i<5;i++)
                            m*=A[i][p[i]-1];
                        if(t%2==0)s+=m;
                        else s-=m;  
                    }
                
    printf("%d\n",s);
    return 0;
}


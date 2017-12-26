 #include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
 
int n=4;
int k,ans=0;
int a[5][5];
bool b[20];
 

//每一个位置，都遍历从1到16的所有可用数字的情况
//此搜索树为16层（包括根节点17层）

//普通实现：当搜索到最后一个位置以后，检验行、列、对角线是否满足要求
//优化实现：一行一行，从上到下搜索，在搜索的时候就保证每一行相加为34，每一列相加为34
//         对于某一行或某一列的最后一个元素，只能有一种情况
//         对于某一行或列已经不满足34的情况下，就不必再搜索其子结点了
//         最后检验对角线

//对最后一个元素检验后，每层节点数为：
//16，15，14，1，13，12，11，1，10，9，8，1，1，1，1，1
//再添加对每个非最后元素的i+z>33的检验，结点数可以更少

//深度优先搜索，每次回退时要将结点中的赋值操作也回退
void dfs(int x,int y,int z)//坐标x，y表示行与列，当前行累加为z 
{
    if (x>n)
    {
        //搜索完所有行后，对角线检查
         if (a[1][1]+a[2][2]+a[3][3]+a[4][4]!=34 || a[1][4]+a[2][3]+a[3][2]+a[4][1]!=34) return;
         ans++;
         if(ans==k)
         {
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                printf("%d ",a[i][j]);
                printf("\n");
            }
            //system("pause");
        }
        return;
    }
    if(y==n)//行优化 
    {
        //对于每一行的最后一列，只能放34-z
        //若此行可满足总和为34，则搜索下一行
        int s=34-z;  
        if (s>0 && s<17 && b[s]==false)
        {
            a[x] [y]=s;
            b[s]=true;
            dfs(x+1,1,0);
            //if(ans==k) return;
            a[x] [y]=0;
            b[s]=false;
        }
        return;
    }
    if (x==n)//列优化 
    {
        int s=34;
        for(int i=1;i<n;i++)s-=a[i][y];
        if (s>0 && s<17 && b[s]==false)
        {
            a[x] [y]=s;
            b[s]=true;
            dfs(x,y+1,z+s);
            //if(ans==k) return;
            a[x] [y]=0;
            b[s]=false;
        }
        return;
    }
    
    for(int i=1;i<=16;i++)
    {
        if (i+z>33) break;
        if (b[i]==false) //!b[i] <===>  b[i]==false
        {
            a[x] [y]=i;
            b[i]=true;
            dfs (x,y+1,z+i);
            //if(ans==k) return;
            b[i]=false;
            a[x] [y]=0;
        }
    }
}
 
int main()
{
    scanf("%d",&k); 
    memset(a,0,sizeof(a));
    memset(b,false,sizeof(b));
    dfs(1,1,0);
}
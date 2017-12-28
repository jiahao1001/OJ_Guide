#include <stdio.h>
int point;
int position[81];
void search(int sudoku[][9],int x,int &res)
{
    if (res>1) return;
    if (x==point) ++res;
    else
    {
        bool s[10];
        int i,j,m=position[x]/9,n=position[x]%9;
        for (i=1;i<=9;++i) s[i]=true;
        for (i=0;i<9;++i) s[sudoku[m][i]]=false;
        for (i=0;i<9;++i) s[sudoku[i][n]]=false;
        for (i=(m/3)*3;i<(m/3+1)*3;++i) for (j=(n/3)*3;j<(n/3+1)*3;++j) s[sudoku[i][j]]=false;
        for (i=1;i<=9;++i) if (s[i])
        {
            sudoku[m][n]=i;
            search(sudoku,x+1,res);
        }
        sudoku[m][n]=0;
    }
}
bool check(int sudoku[][9])
{
    int i,j,m,n;
    int count[10];
    for (i=0;i<9;++i)
    {
        for (j=1;j<=9;++j) count[j]=0;
        for (j=0;j<9;++j) ++count[sudoku[i][j]];
        for (j=1;j<=9;++j) if (count[j]>1) return false;
    }
    for (j=0;j<9;++j)
    {
        for (i=1;i<=9;++i) count[i]=0;
        for (i=0;i<9;++i) ++count[sudoku[i][j]];
        for (i=1;i<=9;++i) if (count[i]>1) return false;
    }
    for (i=0;i<9;i+=3) for (j=0;j<9;j+=3)
    {
        for (m=1;m<=9;++m) count[m]=0;
        for (m=i;m<i+3;++m) for (n=j;n<j+3;++n) ++count[sudoku[m][n]];
        for (m=1;m<=9;++m) if (count[m]>1) return false;
    }
    return true;
}
int main()
{
    bool rec[10];
    int sudoku[9][9];
    int k,i,j,n,res;
    scanf("%d",&n);
    for (k=0;k<n;++k)
    {
        point=0;
        for (i=0;i<9;++i) for (j=0;j<9;++j)
        {
            scanf("%d",&sudoku[i][j]);
            if (sudoku[i][j]==0)
            {
                position[point]=i*9+j;
                ++point;
            }
        }
        if (!check(sudoku)) rec[k]=false;
        else if (point>64) rec[k]=false;
        else if (point<=3) rec[k]=true;
        else
        {
            res=0;
            search(sudoku,0,res);
            rec[k]=(res==1);
        }
    }
    for (k=0;k<n;++k) if (rec[k]) printf("Yes\n");else printf("No\n");
}

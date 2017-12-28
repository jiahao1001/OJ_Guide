#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int point;
int position[81];
void search(int sudoku[][9],int x,int &res)
{
    if (x==point)
    {
        ++res;
        cout<<res<<".\n";
        for (int i=0;i<9;++i)
        {
            for (int j=0;j<9;++j) cout<<sudoku[i][j]<<' ';
            cout<<'\n';
        }
        cout<<'\n';
    }
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
    cout<<"这个程序是用来解数独的，把数独保存到与exe文件同目录下的txt文件中，空位记为0，执行该程序即可求解。\n请输入文件名：";
    char s[26];
    cin>>s;
    cin.get();
    int ll=strlen(s);
    if (s[ll-4]!='.')
    {
        s[ll]='.';
        s[ll+1]='t';
        s[ll+2]='x';
        s[ll+3]='t';
        s[ll+4]='\0';
    }
    ll+=4;
    ifstream fin(s);
    if (!fin)
    {
        cout<<"找不到文件！\n";
        cin.get();
        return 0;
    }
    int sudoku[9][9];
    int i,j,res;
    point=0;
    for (i=0;i<9;++i) for (j=0;j<9;++j)
    {
        fin>>sudoku[i][j];
        if (sudoku[i][j]==0)
        {
            position[point]=i*9+j;
            ++point;
        }
    }
    if (!check(sudoku))
    {
        cout<<"该数独不合法！\n";
        cin.get();
        return 0;
    }
    res=0;
    cout<<"计算结果如下：\n";
    search(sudoku,0,res);
    if (res==0) cout<<"该数独无解。\n";
    fin.close();
    cout<<"谢谢使用！\n";
    cin.get();
}

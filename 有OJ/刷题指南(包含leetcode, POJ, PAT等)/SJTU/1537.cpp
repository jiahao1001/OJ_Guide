#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
bool picked[5][5]={0},check[5][5]={0};
int count=0,chosen[7],data[5][5];
unsigned long long res=0;
/*bool check_point(int i)
{
    int x=i/5,y=i%5;
    return ((x!=0 && picked[x-1][y]) || (y!=0 && picked[x][y-1]) || (x!=4 && picked[x+1][y]) || (y!=4 && picked[x][y+1]));
}*/
bool all_linked()
{
    queue<int> q;
    q.push(chosen[0]);
    int t,x,y;
    for (x=0;x<5;++x) for (y=0;y<5;++y) check[x][y]=false;
    while (!q.empty())
    {
        t=q.front();
        q.pop();
        x=t/5;
        y=t%5;
        check[x][y]=true;
        if (x!=0 && picked[x-1][y] && (!check[x-1][y])) q.push(t-5);
        if (y!=0 && picked[x][y-1] && (!check[x][y-1])) q.push(t-1);
        if (x!=4 && picked[x+1][y] && (!check[x+1][y])) q.push(t+5);
        if (y!=4 && picked[x][y+1] && (!check[x][y+1])) q.push(t+1);
    }
    for (t=0;t<7;++t) if (!check[chosen[t]/5][chosen[t]%5]) return false;
    return true;
}
void search(int n)
{
    if (count==7)
    {
        if (all_linked())
        {
            int i,t=0;
            for (i=0;i<7;++i) t+=data[chosen[i]/5][chosen[i]%5];
            if (t>0)
            {
                ++res;
                //for (i=0;i<7;++i) cout<<'('<<chosen[i]/5<<','<<chosen[i]%5<<") ";
                //cout<<'\n';
            }
        }
        return;
    }
    if (n==25) return;
    picked[n/5][n%5]=true;
    chosen[count]=n;
    ++count;
    search(n+1);
    picked[n/5][n%5]=false;
    --count;
    search(n+1);
}
int main()
{
    //ifstream fin("1537.in");
    char s[6];
    int i,j;
    for (i=0;i<5;++i)
    {
        cin>>s;
        for (j=0;j<5;++j)
        {
            if (s[j]=='H') data[i][j]=-1;
            else data[i][j]=1;
        }
    }
    search(0);
    cout<<res;
    //fin.close();
}

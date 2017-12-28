#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 3010;
int d[N],f[N];
bool v[N];
int n,m,x,y,z;
int a[N][N];
int dfn[N];
int curr;
int b[N][N];
int prim()
{
    int tot = 0;
    memset(d,63,sizeof(d));
    memset(v,0,sizeof(v));
    memset(f,0,sizeof(f));
    v[0] = 1; d[0] = 0;
    for (int i = 1; i < n; i++)
    {
        d[i] = a[0][i];
        f[i] = 0;
    }
    for (int i = 1; i < n; i++)
    {
        int k = 0,minn = 1000000000;
        for (int j = 0; j < n; j++)
            if (!v[j] && d[j] < minn)
            {
                minn = d[j];
                k = j;
            }
        tot += d[k];
        v[k] = 1;
        for (int j = 0; j < n; j++)
            if (!v[j] && d[j] > a[k][j])
            {
                d[j] = a[k][j];
                f[j] = k;
            }
    }
    return tot;
}
void dfs(int x)
{
    for (int i = 0; i < n; i++)
        if (f[i] == x )
        {
            dfs(i);
            for (int j = 0; j < n; j++) b[x][j] = min(b[x][j],b[i][j]);
        }
    for (int i = 0; i < n; i++)
        b[x][i] = min(b[x][i],a[x][i]);
}
int main()
{
    while (scanf("%d%d",&n,&m) != EOF)
    {
        if (n == 0 && m ==0) break;
        memset(a,63,sizeof(a));
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if (x != y) a[x][y] =a[y][x] = z;
        }
        int ans = prim();
        memset(b,63,sizeof(b));
        for (int i = 0; i < n; i++) a[i][i] = -1;
        f[0] = -1;
        dfs(0);
        int q;
        scanf("%d",&q);
        long long sum = 0;
        for (int i = 0; i < q; i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            if (f[x] == y || f[y]==x)
            {
                if(f[y]==x)swap(x,y);
                int minn = 1000000000;
                sum = sum + ans;
                sum -= a[x][y];
                for (int j = 0; j < n; j++)
                    if (j != y && b[x][j] != -1) minn = min(minn,b[x][j]);
                for (int j = 0; j < n; j++)
                    if (f[j] == x && b[j][y] != -1) minn = min(minn,b[j][y]);
                minn = min(minn,z);
                sum += minn;
            }
            else sum += ans;
        }
        double fin = sum;
        fin = fin / q;
        printf("%.4f\n",fin);
    }
    return 0;
}

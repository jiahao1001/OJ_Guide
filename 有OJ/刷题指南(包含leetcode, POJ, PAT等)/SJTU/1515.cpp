#include <stdio.h>
#include <queue>
using namespace std;
bool **original;
int **home, **cere;
int home_pos, cere_pos, stores=0, n, m;
bool in(int x, int y)
{
    return (x >= 0 && x < m && y >= 0 && y < n);
}
void search(int **map, int start)
{
    int search_count=0;
    queue< int > q;
    q.push(start);
    int x, y;
    map[start/n][start%n]=1;
    while (!q.empty())
    {
        x=q.front() / n;
        y=q.front() % n;
        if (original[x][y]) ++search_count;
        if (search_count >= stores) return;
        q.pop();
        if (in(x-1, y) && map[x-1][y] == 0)
        {
            q.push((x-1) * n + y);
            map[x-1][y]=map[x][y] + 1;
        }
        if (in(x, y-1) && map[x][y-1] == 0)
        {
            q.push(x*n + y-1);
            map[x][y-1]=map[x][y] + 1;
        }
        if (in(x+1, y) && map[x+1][y] == 0)
        {
            q.push((x+1) * n + y);
            map[x+1][y]=map[x][y] + 1;
        }
        if (in(x, y+1) && map[x][y+1] == 0)
        {
            q.push(x*n + y+1);
            map[x][y+1]=map[x][y] + 1;
        }
    }
}
int main()
{
    //FILE *fp = fopen("1515.in", "r");
    int i, j, t, x, y, min = 2000000;
    scanf("%d %d", &n, &m);
    queue<int> ps;
    original = new bool*[m];
    home = new int*[m];
    cere = new int*[m];
    for (i = 0; i < m; ++i)
    {
        original[i] = new bool[n];
        home[i] = new int[n];
        cere[i] = new int[n];
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &t);
            original[i][j] = (t == 4);
            cere[i][j] = home[i][j] = (t==1) ? -1 : 0;
            if (t==2) cere_pos = i * n + j;
            else if (t == 3) home_pos = i * n + j;
            else if (t == 4)
            {
                ps.push(i * n + j);
                ++stores;
            }
        }
    }
/*
    printf("before:\n");
    for (i = 0;i < m; ++i)
    {
        for (j = 0; j < n; ++j) printf("%d    ", cere[i][j]);
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j) printf("%d    ", home[i][j]);
        printf("\n");
    }
*/
    search(cere, cere_pos);
    search(home, home_pos);
/*
    printf("after:\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0;j < n; ++j) printf("%d    ", cere[i][j]);
        printf("\n");
    }
    printf("\n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j) printf("%d    ", home[i][j]);
        printf("\n");
    }
*/
    while (!ps.empty())
    {
        x = (ps.front()) / n;
        y = (ps.front()) % n;
        ps.pop();
        if (cere[x][y]!=0)
        {
            t = cere[x][y] + home[x][y] -2;
            if (t < min) min = t;
        }
    }
    for (i = 0; i < m; ++i)
    {
        delete [] original[i];
        delete [] home[i];
        delete [] cere[i];
    }
    delete [] original;
    delete [] home;
    delete [] cere;
    printf("%d\n", min);
    //fclose(fp);
}

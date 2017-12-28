#include<stdio.h>
int maze[5][5] = {0};
int visit[5][5] = {0};
void dfs(int i, int j)
{
    if (i+1 < 5 && maze[i+1][j] == 0 && (visit[i+1][j] == 0 || visit[i+1][j] > visit[i][j] + 1)) {
        visit[i+1][j] = visit[i][j] + 1;
        dfs(i+1, j);
    }
    if (j+1 < 5 && maze[i][j+1] == 0 && (visit[i][j+1] == 0 || visit[i][j+1] > visit[i][j] + 1)) {
        visit[i][j+1] = visit[i][j] + 1;
        dfs(i, j+1);
    }
    if (i-1 >= 0 && maze[i-1][j] == 0 && (visit[i-1][j] == 0 || visit[i-1][j] > visit[i][j] + 1)) {
        visit[i-1][j] = visit[i][j] + 1;
        dfs(i-1, j);
    }
    if (j-1 >= 0 && maze[i][j-1] == 0 && (visit[i][j-1] == 0 || visit[i][j-1] > visit[i][j] + 1)) {
        visit[i][j-1] = visit[i][j] + 1;
        dfs(i, j-1);
    }
}
int main()
{
    int i, j, k;
    int stack[25][2] = {0};
    for (i=0; i<5; i++)
    {
        for (j=0; j<5; j++)
        {
            scanf("%d", &maze[i][j]);
        }
    }
    visit[0][0] = 1;
    dfs(0, 0);
    for (i=4, j=4, k=0; i!=0 || j!=0; k++) {
        stack[k][0] = i;
        stack[k][1] = j;
        if (i+1 < 5 && visit[i+1][j] == visit[i][j] - 1) {
            i = i + 1;
        }
        else if (j+1 < 5 && visit[i][j+1] == visit[i][j] - 1) {
            j = j + 1;
        }
        else if (i-1 >= 0 && visit[i-1][j] == visit[i][j] - 1) {
            i = i - 1;
        }
        else if (j-1 >= 0 && visit[i][j-1] == visit[i][j] - 1) {
            j = j - 1;
        }
    }
    stack[k][0] = 0;
    stack[k][1] = 0;
    for (i=k; i>=0; i--)
    {
        printf("(%d, %d)\n", stack[i][0], stack[i][1]);
    }
    return 0;
}
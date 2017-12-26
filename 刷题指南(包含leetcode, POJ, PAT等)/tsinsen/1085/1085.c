
/**
 参考标准程序实现，略微改动。
 主要改动点为：vector<vector<int> > blackpic(pic); 使用pic直接初始化blackpic，
 而不是先声明然后遍历复制。
*/

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int cnt = 0;
int n;

bool isSafe(vector<int> pos, int row)
{
    int i;
    for(i = 0;i < row;i++)
    {
        if(pos[i] == pos[row] || abs(row-i) == abs(pos[row]-pos[i]))
            return false;
    }
    return true;
}

void blackdfs(vector<vector<int> > blackpic, vector<int> blackpos, int row)
{
    if(row == n)
    {
        cnt++;
        return;
    }
    for(blackpos[row] = 0; blackpos[row] < n; blackpos[row]++)
    {
        if(blackpic[row][blackpos[row]] == 1 && isSafe(blackpos, row))
            blackdfs(blackpic, blackpos, row + 1);
    }
}

void dfs(vector<vector<int> > pic, vector<int> pos, int row)
{
    if(row == n)
    {
        vector<vector<int> > blackpic(pic);
        for(int i = 0; i < n; i++) {
            blackpic[i][pos[i]] = 0;
        }
        vector<int> blackpos(n);
        blackdfs(blackpic, blackpos, 0);
        return ;
    }
    for(pos[row] = 0; pos[row] < n; pos[row]++)
    {
        if(pic[row][pos[row]] == 1 && isSafe(pos, row))
            dfs(pic, pos, row + 1);
    }
}

int main()
{
    cin >> n;
    vector<vector<int> > pic(n, vector<int>(n));
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> pic[i][j];
        }
    }
    dfs(pic, pos, 0);
    cout << cnt <<endl;
    return 0;
}
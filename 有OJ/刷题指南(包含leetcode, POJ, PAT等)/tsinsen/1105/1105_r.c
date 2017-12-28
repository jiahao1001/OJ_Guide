
/**
 采用递归实现，AC
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


int N, w[15], flag[15];  //地雷个数，是否已访问
int matrix[15][15];  //邻接矩阵
vector<int> path_cur(15), path_ans(15); //当前路径，最终结果的路径
int ans, max1 = 0;  //当前地雷个数，最大地雷个数


void dfs(int x, int v) {
    bool find = false;
    for(int j = 1; j <= N; j++) {
        if(matrix[x][j] && !flag[j]) {
            find = true;
            path_cur.push_back(j);
            flag[j] = 1;
            v += w[j];
            dfs(j, v);
            v -= w[j];
            flag[j] = 0;
            path_cur.pop_back();
        }
    }
    if(!find) {
        if(v > max1) {
            max1 = v;
            path_ans = path_cur;
        }
    }
}

int main() {
    int i, j, k;
    cin >> N;
    if(N == 0) {
        cout << "MAX=" << 0 << endl;
        return 0;
    }
    for(i = 1; i <= N; i++) {
        cin >> w[i];
    }
    memset(matrix, 0, sizeof(matrix));
    for(i = 1; i <= N - 1; i++) {
        for(j = 1; i + j <= N; j++) {
            cin >> matrix[i][i + j];
            matrix[i + j][i] = matrix[i][i + j];
        }
    }
    path_ans.clear();
    for(i = 1; i <= N; i++) {  //从任一个起点开始
        path_cur.clear();
        path_cur.push_back(i);
        flag[i] = 1;
        ans = w[i];
        dfs(i, ans);
        flag[i] = 0;
    }  

    for(i = 0; i < path_ans.size() - 1; i++) {
        cout << path_ans[i] << '-';
    }
    if(i == path_ans.size() - 1)cout << path_ans[i] << endl;
    cout << "MAX=" << max1 << endl;
    return 0;
}
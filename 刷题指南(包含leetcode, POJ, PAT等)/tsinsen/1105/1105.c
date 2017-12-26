
/**
 采用栈实现，无法通过最后一个测试点
*/

#include <iostream>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int N, w[15], flag[15];  //地雷个数，是否已访问
    int matrix[15][15];  //邻接矩阵
    vector<int> path_cur(15), path_ans(15); //当前路径，最终结果的路径
    path_ans.clear();
    int ans, max = 0;  //当前地雷个数，最大地雷个数
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

    for(i = 1; i <= N; i++) {  //从任一个起点开始

        memset(flag, 0, sizeof(flag));
        stack<int> s;
        s.push(i);   
        path_cur.clear();
        path_cur.push_back(i); //将地窖i设为路径起点
        ans = w[i];
        flag[i] = 1;

        while(!s.empty()) {
            int cur = s.top();
            for(j = 1; j <= N; j++) {
                if(matrix[cur][j] && !flag[j]) {
                    s.push(j);
                    path_cur.push_back(j);  //将地窖j加入到路径
                    ans += w[j];
                    flag[j] = 1;
                    break;
                }
            }
            if(j == N + 1) {  //如果当前地窖没有未访问的连通结点
                if(ans > max) {
                    max = ans;
                    path_ans = path_cur;
                }
                ans -= w[cur];
                s.pop();
                path_cur.pop_back();
            }
        }
    }

    for(i = 0; i < path_ans.size() - 1; i++) {
        cout << path_ans[i] << '-';
    }
    if(i == path_ans.size() - 1)cout << path_ans[i] << endl;
    cout << "MAX=" << max << endl;
    return 0;
}
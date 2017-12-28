#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;


int main() {
    int n, i, j, k;
    cin >> n;
    n = pow(2, n);
    int pair[n + 10][n + 10], flag[n + 10];
    memset(pair, 0, sizeof(pair));
    memset(flag, 0, sizeof(flag));
    for(i = 1; i < n; i++) {
        cout << "<" << i << ">";
        for(j = 1; j <= n; j++) {
            if(!flag[j]) {
                for(k = j + 1; k <= n; k++) {
                    if(!flag[k] && !pair[j][k] && !pair[k][j]) {
                        flag[k] = 1;
                        pair[k][j] = pair[j][k] = 1;
                        cout << j << "-" << k << ' ';
                        break;
                    }
                }
            }
        }
        cout << endl;
        memset(flag, 0, sizeof(flag));
    }
}
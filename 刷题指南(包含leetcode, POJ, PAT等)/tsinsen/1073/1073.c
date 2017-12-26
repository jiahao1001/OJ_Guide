#include <cstdio>
#include <iostream>
#include <cstring>

#define MAXN 105

using namespace std;

int a[MAXN][MAXN], b[MAXN][MAXN];
int ans[MAXN][MAXN];

int main()
{
    int n;
    cin >> n;

    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            ans[i][j] = a[i][j] + b[i][j];
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
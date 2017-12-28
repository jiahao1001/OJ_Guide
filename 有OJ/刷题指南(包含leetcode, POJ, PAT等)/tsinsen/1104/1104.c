#include <iostream> 
#include <algorithm>
using namespace std;

int main() {
    int w[] = {1, 2, 3, 5, 10, 20};
    int n[6];
    int V[2000] = {1};
    int i, j, N, sum = 0, v, ans = 0;
    for(i = 0; i < 6; i++) {
        cin >> n[i];
        sum += n[i] * w[i];
    }
    for(i = 0; i < 6; i++) {
        for(j = 1; j <= n[i]; j = j<<1) {
            for(v = sum; v >= j * w[i]; v--) {
                V[v] = max(V[v], V[v - j * w[i]]);
            }
            n[i] -= j;
        }
        j = n[i];
        for(v = sum; v >= j * w[i]; v--) {
            V[v] = max(V[v], V[v - j * w[i]]);
        }
    }
    for(i = 1; i <= sum; i++)
        if(V[i] == 1)
            ans++;
    cout << "Total=" << ans << endl;
    return 0;
}
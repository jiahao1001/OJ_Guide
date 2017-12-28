#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <limits.h>
using namespace std;

int main() {

    int N, ML, MD;
    cin >> N >> ML >> MD;

    int edges[ML + MD + N - 1][3];
    int E = 0;

    for (int i = 0; i + 1 < N; i++) {
        edges[E][0] = i + 1;
        edges[E][1] = i;
        edges[E][2] = 0;
        E++;
    }
    for (int i = 0; i < ML; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        a--; b--;
        if (a > b) swap(a, b);
        edges[E][0] = a;
        edges[E][1] = b;
        edges[E][2] = l;
        E++;
    }
    for (int i = 0; i < MD; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        a--; b--;
        if (a > b) swap(a, b);
        edges[E][0] = b;
        edges[E][1] = a;
        edges[E][2] = -d;
        E++;
    }

    int dist[N];
    fill(dist + 1, dist + N, INT_MAX);
    dist[0] = 0;
    for (int i = 0; i < N-1; i++)
        for (int j = 0; j < E; j++)
            if (dist[edges[j][0]] != INT_MAX)
                dist[edges[j][1]] =  min(dist[edges[j][1]],dist[edges[j][0]] + edges[j][2]);
    if (dist[N - 1] == INT_MAX) {
        cout<<-2<<endl;
        return 0;
    }
    for (int j = 0; j < E; j++)
        if (dist[edges[j][0]] != INT_MAX
            && dist[edges[j][1]] > dist[edges[j][0]] + edges[j][2]){
            cout<<-1<<endl;
            return 0;
        }
    cout<<dist[N-1]<<endl;
    return 0;
}

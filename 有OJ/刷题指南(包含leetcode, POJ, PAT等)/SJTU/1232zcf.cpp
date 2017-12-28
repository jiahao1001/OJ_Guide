#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
struct Node
{
    int parent;
    int near[4];
    Node(void){near[0] = 0; near[1] = 0; near[2] = 0; near[3] = 0;}
};
Node data[1000001];
int num, start_point, end_point, layer, total_layer, root;
int route[1000001]; int tail = 0;
bool visited[1000001] = {0};
bool dfs_flag;
int return_layer(int k)
{
    double ans = 1.0 / 2 + sqrt(1.0 + 8 * k) / 2;
    if((int)ans == ans) return ans-1;
    else return (int)ans;
}
void combine(int a, int b)
{
    int curr_a = a, curr_b = b;
    while(data[curr_a].parent > 0) curr_a = data[curr_a].parent;
    while(data[curr_b].parent > 0) curr_b = data[curr_b].parent;
    if(curr_a != curr_b)
    {
        if(data[curr_a].parent > data[curr_b].parent) {data[curr_b].parent += data[curr_a].parent; data[curr_a].parent = curr_b;}
        else {data[curr_a].parent += data[curr_b].parent; data[curr_b].parent = curr_a;}
    }
}
bool not_together(int a, int b)
{
    int curr_a = a, curr_b = b;
    while(data[curr_a].parent > 0) curr_a = data[curr_a].parent;
    while(data[curr_b].parent > 0) curr_b = data[curr_b].parent;
    return curr_a != curr_b;
}
int find_root(int a)
{
    int curr_a = a;
    while(data[curr_a].parent > 0) curr_a = data[curr_a].parent;
    return curr_a;
}
void dfs(void)
{
    if(!dfs_flag)
    {
        for(int index = 0; index < 4; index++)
        {
            if(data[route[tail]].near[index] && !visited[data[route[tail]].near[index]])
            {
                route[tail+1] = data[route[tail]].near[index];++tail;
                visited[route[tail]] = 1;
                if(route[tail] == end_point) {dfs_flag = true; return ;}
                dfs();
                if(route[tail] == end_point) {dfs_flag = true; return ;}
                visited[route[tail]] = 0;
                tail--;
            }
        }
    }
}

int main()
{
    int a, b;
    bool flag = true;
    scanf("%d %d %d", &total_layer, &start_point, &end_point);
    num = total_layer * (total_layer + 1) / 2;
    for(int index = 1; index <= num; index++) data[index].parent = -1;
    while(scanf("%d %d", &a, &b) == 2 && flag)
    {
        layer = return_layer(a);
        switch(b)
        {
        case 0:
            {
                if(return_layer(a - layer) == layer-1)
                {
                    combine(a, a-layer);
                    data[a].near[0] = a-layer;
                    data[a-layer].near[3] = a;
                }
                break;
            }
        case 1:
            {
                if(return_layer(a - layer + 1) == layer-1)
                {
                    combine(a, a-layer+1);
                    data[a].near[1] = a-layer+1;
                    data[a-layer+1].near[2] = a;
                }
                break;
            }
        case 2:
            {
                if(return_layer(a + layer) <= total_layer)
                {
                    combine(a, a+layer);
                    data[a].near[2] = a+layer;
                    data[a+layer].near[1] = a;
                }
                break;
            }
        case 3:
            {
                if(return_layer(a + layer + 1) <= total_layer)
                {
                    combine(a, a+layer+1);
                    data[a].near[3]  =a+layer+1;
                    data[a+layer+1].near[0] = a;
                }
                break;
            }
        }
        flag = not_together(start_point, end_point);
    }
    root = find_root(start_point);
    route[++tail] = start_point;
    visited[start_point] = 1;
    dfs_flag = false; dfs();
    for(int index = 1; index <= tail; index++) printf("%d ", route[index]);
    return 0;
}

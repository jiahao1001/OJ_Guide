#include<stdio.h>
#include<queue>
using namespace std;
void bfs(int n)
{
    queue<long long> Q;
    Q.push(1);
    while(!Q.empty())
    {
        long long h=Q.front();
        Q.pop();
        if(h%n==0){
            printf("%lld\n",h);
            return;
        }
        Q.push(h*10);
        Q.push(h*10+1);
    }
    
}

int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        bfs(n);
    }
    return 0;
}

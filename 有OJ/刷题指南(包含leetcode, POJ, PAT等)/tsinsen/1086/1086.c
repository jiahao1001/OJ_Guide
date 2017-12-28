#include <iostream>
#include <cstdlib>

#define MAX 999999

using namespace std;

int cost = 0;
int n, ans = 0;
int a[110];

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    cin>>n;
    int i, j;
    for(i = 0; i < n; i++)
        cin>>a[i];
    qsort(a, n, sizeof(int), cmp);
    for(i = 0; i < n; i++)
    {
        if(a[1]==MAX)break;
        ans += a[0] + a[1];
        a[0] += a[1];
        a[1] = MAX;
        qsort(a, n, sizeof(int), cmp);
    }
    cout << ans <<endl;
    return 0;
}
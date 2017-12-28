#include <cstdio>
void input(int* data,int n)
{
    char f;int i;
    getchar();
    getchar();
    for (i=0;i<n;++i)
    {
        scanf("%d",&data[i]);
        scanf("%c",&f);
        //printf("%d ",data[i]);
    }
    //printf("\n");
}
int main()
{
    freopen("1550.in","r",stdin);
    int n, i;
    scanf("%d",&n);
    int *height = new int[n];
    input(height, n);
    int max=0, res=0, l=0, r=n-1;
    for (i=0;i<n;++i)
    {
        res -= height[i];
        if (max < height[i]) max = height[i];
    }
    for (i=1;i<=max;++i)
    {
        while (height[l] < i) ++l;
        while (height[r] < i) --r;
        res += (r-l+1);
    }
    printf("%d\n", res);
    delete [] height;
}

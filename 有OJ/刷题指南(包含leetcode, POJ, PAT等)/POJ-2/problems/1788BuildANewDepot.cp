#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100000+10;
struct Point
{
    int x,y;
}P[maxn];
bool compare_x(Point A,Point B)//升序排列
{
    return A.x<B.x || (A.x==B.x&&A.y<B.y);
}
bool compare_y(Point A,Point B)
{
    return A.y<B.y || (A.y==B.y&&A.x<B.x);
}


int main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=0;i<n;++i) scanf("%d%d",&P[i].x,&P[i].y);
        int ans=0;
        sort(P,P+n,compare_x);
        for(int i=0;i<n;)
        {
            if(P[i].x==P[i+1].x)//计算竖直边
            {
                ans += P[i+1].y-P[i].y;
                i+=2;
            }
            else ++i;
        }
        sort(P,P+n,compare_y);
        for(int i=0;i<n;)
        {
            if(P[i].y==P[i+1].y)//计算水平边
            {
                ans+= P[i+1].x-P[i].x;
                i+=2;
            }
            else ++i;
        }
        printf("The length of the fence will be %d units.\n",ans);
    }
    return 0;
}

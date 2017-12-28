#include <stdio.h>
#include <queue>
using namespace std;
int main()
{
    FILE *fp=fopen("1348.in","r");
    queue<unsigned> songs,dancers[2];
    double wait[2]={0,0};
    int n,m,i,x;
    unsigned sum=0,t,y;
    int num[2]={0,0};
    fscanf(fp,"%d",&n);
    for (i=0;i<n;++i)
    {
        fscanf(fp,"%d",&t);
        songs.push(sum);
        sum+=t;
    }
    fscanf(fp,"%d",&m);
    for (i=0;i<m;++i)
    {
        fscanf(fp,"%d %l64d",&x,&y);
        ++num[x-1];
        //printf("%d\n",y);
        dancers[x-1].push(y);
    }
    while (!songs.empty())
    {
        if (dancers[0].empty() || dancers[1].empty()) break;
        while (dancers[0].front()<=songs.front() && dancers[1].front()<=songs.front())
        {
            wait[0]+=songs.front()-dancers[0].front();
            wait[1]+=songs.front()-dancers[1].front();
            //printf("%d %d\n",dancers[0].front(),dancers[1].front());
            dancers[0].pop();
            dancers[1].pop();
        }
        songs.pop();
    }
    songs.push(sum);
    while (!dancers[0].empty())
    {
        wait[0]+=songs.front()-dancers[0].front();
        dancers[0].pop();
    }
    while (!dancers[1].empty())
    {
        wait[1]+=songs.front()-dancers[1].front();
        dancers[1].pop();
    }
    printf("%0.2f %0.2f",wait[0]/num[0],wait[1]/num[1]);
}

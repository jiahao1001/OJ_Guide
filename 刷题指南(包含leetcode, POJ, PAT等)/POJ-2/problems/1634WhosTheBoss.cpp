#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int n,m,q,y,k;
struct node
{
    int id,sala,height;
    int boss,child;
    vector<int> sub;
    bool operator<(const node& o)const
    {
        return sala>o.sala;
    }
}person[30010];
int main()
{
    int i,j;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&m,&q);
        for(i=0;i<m;++i)
        {
            scanf("%d%d%d",&person[i].id,&person[i].sala,&person[i].height);
            person[i].sub.clear();
            person[i].child=0;
        }
        sort(person,person+m);
        for(i=m-1;i>=0;--i)
        {
            for(j=i-1;j>=0;--j)
                if(person[j].height>=person[i].height)
                    break;
            if(j>=0)
            {
                person[i].boss=j;
                person[j].sub.push_back(i);
            }
            else
                person[i].boss=-1;
        }
        for(i=m-1;i>=0;--i)
        {
            if(person[i].sub.size()>0)
            {
                for(j=0;j<person[i].sub.size();++j)
                    person[i].child+=person[person[i].sub[j]].child+1;
            }
        }
        int id;
        while(q--)
        {
            scanf("%d",&id);
            for(i=0;i<m;++i)
                if(person[i].id==id)
                    break;
            if(person[i].boss==-1)
                printf("0 %d\n",person[i].child);
            else
                printf("%d %d\n",person[person[i].boss].id,person[i].child);
        }
    }
    return 0;
}
